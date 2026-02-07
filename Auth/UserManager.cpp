#include "UserManager.h"
#include <iostream>
#include "../search/HammingDistance.h"
UserManager::UserManager()
{
	currentUser = nullptr;
    nextPostId = 0;
}

vector<string> UserManager::searchUser(const string& prefix) {
    currentUser->addSearchHistory(prefix);
    return userTrie.prefixSearch(prefix);
}

bool UserManager::signup(const string& username, const string& password) {

    if (users.find(username) != users.end()) {
        return false;
    }


    User* newUser = new User(username, password);
    users[username] = newUser;
    userTrie.insert(username);
    return true;
}

bool UserManager::login(const string& username, const string& password) {
    if (currentUser != nullptr) {
        cout << "another user is login"<<endl;
        return false;
    }
    // اگر کاربر وجود ندارد
    if (users.find(username) == users.end()) {
        cout << "Error: invalid username or password\n";
        return false;
    }

    User* user = users[username];

    // بررسی رمز عبور
    if (!user->checkPassword(password)) {
        cout << "Error: invalid username or password\n";
        return false;
    }

    currentUser = user;
    return true;
}

void UserManager::logout() {
    currentUser = nullptr;
}

User* UserManager::getCurrentUser() const {
    return currentUser;
}

User* UserManager::getUser(const string& username) const {
    auto it = users.find(username);
    if (it != users.end())
        return it->second;

    return nullptr;
}

bool UserManager::createPost(const string& content) {

    if (currentUser == nullptr)
        return false;

    int postId = nextPostId++;

    Post* newPost = new Post(
        postId,
        currentUser->getUsername(),
        content
    );

    posts[postId] = newPost;
    currentUser->addPost(postId);

    // ✅ فقط اگر پست با هشتگ شروع شود
    if (!content.empty() && content[0] == '#') {
        string hashtag;

        // جدا کردن هشتگ از متن
        size_t spacePos = content.find(' ');
        if (spacePos == string::npos)
            hashtag = content.substr(1);              // #hello
        else
            hashtag = content.substr(1, spacePos - 1); // #hello world

        invertedIndex.addPost(postId, hashtag);
    }

    return true;
}



Post* UserManager::getPost(int postId) {
    if (!posts.count(postId))
        return nullptr;
    return posts.at(postId);
}

unordered_map<int, Post*>& UserManager::getPosts() {
    return posts;
}

//unordered_map<string, User*>& UserManager::getUsers() {
//    return users;
//}
vector<Post*> UserManager::searchPosts(const string& word) {
    vector<Post*> result;
    auto ids = invertedIndex.search(word);

    for (int id : ids) {
        if (posts.count(id))
            result.push_back(posts[id]);
    }
    return result;
}
bool UserManager::likePost(int postId) {

    // 1️⃣ کاربر لاگین باشد
    if (!currentUser)
        return false;

    // 2️⃣ پست وجود داشته باشد
    if (!posts.count(postId))
        return false;

    Post* post = posts[postId];

    // 3️⃣ تلاش برای لایک
    bool liked = post->like(currentUser->getUsername());

    // ✅ اگر لایک موفق بود، چاپ کن
    if (liked) {
        cout << "Post " << postId
            << " with content: \""
            << post->getContent()
            << "\" liked successfully\n";
    }

    return liked;
}


string UserManager::smartSearchUser(const string& term) {
    if (!currentUser) return "";


    if (users.count(term))
        return term;

    int bestDist = INT_MAX;
    string bestMatch = "";

    for (auto& u : users) {
        int dist = hammingDistance(term, u.first);
        if (dist < bestDist) {
            bestDist = dist;
            bestMatch = u.first;
        }
    }

    currentUser->addSearchHistory(bestMatch);
    return bestMatch;
}


void UserManager::showSearchHistory() const {
    if (!currentUser) {
        cout << "No user logged in\n";
        return;
    }

    auto history = currentUser->getSearchHistory();
    if (history.empty()) {
        cout << "Search history is empty\n";
        return;
    }

    for (const auto& term : history) {
        cout << term << endl;
    }
}


UserManager::~UserManager() {
    for (auto& pair : users)
        delete pair.second;

    for (auto& pair : posts)
        delete pair.second;
}

bool UserManager::follow(const string& username) {
    if (!currentUser) {
        cout << "Error: no user is logged in\n";
        return false;
    }

    User* target = getUser(username);
    if (!target) {
        cout << "Error: user not found\n";
        return false;
    }

    // جلوگیری از فالو کردن خود
    if (currentUser->getUsername() == username) {
        cout << "Error: cannot follow yourself\n";
        return false;
    }

    // اگر قبلاً فالو کرده
    if (currentUser->getFollowing().count(username)) {
        cout << "Error: already following this user\n";
        return false;
    }

    // آپدیت User
    currentUser->follow(username);
    target->addFollower(currentUser->getUsername());

    // آپدیت Graph
    graph.follow(currentUser->getUsername(), username);

    // ✅ پیام موفقیت
    cout << currentUser->getUsername()
        << " followed "
        << username << endl;

    return true;
}


bool UserManager::unfollow(const string& username) {
    if (!currentUser) {
        cout << "Error: no user is logged in\n";
        return false;
    }

    User* target = getUser(username);
    if (!target) {
        cout << "Error: user not found\n";
        return false;
    }

    // اگر اصلاً فالو نکرده
    if (!currentUser->getFollowing().count(username)) {
        cout << "Error: you are not following this user\n";
        return false;
    }

    // آپدیت User
    currentUser->unfollow(username);
    target->removeFollower(currentUser->getUsername());

    // آپدیت Graph
    graph.unfollow(currentUser->getUsername(), username);

    // ✅ پیام موفقیت
    cout << currentUser->getUsername()
        << " unfollowed "
        << username << endl;

    return true;
}

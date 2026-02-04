#include "UserManager.h"

UserManager::UserManager()
{
	currentUser = nullptr;
    nextPostId = 1;
}

bool UserManager::signup(const string& username, const string& password) {

    if (users.find(username) != users.end()) {
        return false;
    }


    User* newUser = new User(username, password);
    users[username] = newUser;

    return true;
}

bool UserManager::login(const string& username, const string& password) {
    // اگر کاربر وجود ندارد
    if (users.find(username) == users.end()) {
        return false;
    }

    User* user = users[username];

    // بررسی رمز عبور
    if (!user->checkPassword(password)) {
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

bool UserManager::createPost(const string& content)
{
    if (currentUser == nullptr)
        return false;

    int id = nextPostId++;
    Post* post = new Post(id, currentUser->getUsername(), content);

    posts[id] = post;
    currentUser->addPost(id);

    return true;
}

Post* UserManager::getPost(int postId) {
    if (posts.find(postId) == posts.end())
        return nullptr;
    return posts[postId];
}

UserManager::~UserManager() {
    for (auto& pair : users)
        delete pair.second;

    for (auto& pair : posts)
        delete pair.second;
}

bool UserManager::follow(const string& username) {
    if (!currentUser) return false;

    User* target = getUser(username);
    if (!target) return false;

    // آپدیت User
    currentUser->follow(username);
    target->addFollower(currentUser->getUsername());

    // آپدیت Graph
    graph.follow(currentUser->getUsername(), username);

    return true;
}

bool UserManager::unfollow(const string& username) {
    if (!currentUser) return false;

    User* target = getUser(username);
    if (!target) return false;

    currentUser->unfollow(username);
    target->removeFollower(currentUser->getUsername());

    graph.unfollow(currentUser->getUsername(), username);

    return true;
}




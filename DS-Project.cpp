#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include "Auth/UserManager.h"
#include "search/Trie.h"
#include "Feed/FeedManager.h"
#include"Search/HammingDistance.h"
using namespace std;

int main() {
    UserManager um;
    um.signup("ali", "123");
    um.signup("alireza", "123");
    um.login("alireza", "123");
    cout << "Smart search result:\n";
    string result1 = um.smartSearchUser("alirezaa");
    string result = um.smartSearchUser("alir");
    if (!result.empty())
        cout << "Did you mean " << result << "?\n";
    um.showSearchHistory();
    //hammingDistance();
    //FeedManager fm;

    //// ---------- ساخت کاربران ----------
    //um.signup("ali", "123");
    //um.signup("reza", "123");
    //um.signup("sara", "123");

    //// ---------- follow ----------
    //um.login("ali", "123");
    //um.follow("reza");
    //um.follow("sara");
    //um.logout();

    //// ---------- reza پست می‌گذارد ----------
    //um.login("reza", "123");
    //um.createPost("reza post 1");
    //this_thread::sleep_for(chrono::seconds(2));
    //um.createPost("reza post 2");
    //um.logout();

    //// ---------- sara پست می‌گذارد ----------
    //um.login("sara", "123");
    //um.createPost("sara post 1");
    //um.logout();

    //// ---------- لایک‌ها ----------
    //um.login("ali", "123");
    //um.likePost(0);
    //um.likePost(1);
    //um.likePost(2);
    //um.logout();

    //um.login("reza", "123");
    //um.likePost(2);   // reza، پست sara رو لایک می‌کنه
    //um.logout();

    //// ---------- تست Feed ----------
    //um.login("ali", "123");

    //vector<Post*> feed = fm.getTopFeed(
    //    um.getCurrentUser(),
    //    um.getPost(),
    //    um.getUser()
    //);

    //cout << "===== SMART FEED =====\n";
    //for (Post* p : feed) {
    //    cout << "PostID: " << p->getId()
    //        << " | Author: " << p->getAuthor()
    //        << " | Likes: " << p->getLikeCount()
    //        << " | Content: " << p->getContent()
    //        << endl;
    //}

    //um.logout();
    //return 0;
    //UserManager um;

    //um.signup("ali", "123");
    //um.login("ali", "123");

    //um.createPost("First post");
    //um.createPost("Second post");

    //cout << um.getPost(0)->getLikeCount() << endl;
    //cout << um.getPost(1)->getLikeCount() << endl;
    //return 0;
    //cout << "=== SIGNUP ===" << endl;
    //um.signup("reza", "123");
    //um.signup("sara", "123");

    //cout << "\n=== LOGIN ali ===" << endl;
    //if (!um.login("ali", "123")) {
    //    cout << "Login failed!" << endl;
    //    return 0;
    //}

    //cout << "\n=== CREATE POSTS ===" << endl;
    //bool p1 = um.createPost("Hello World #first");
    //bool p2 = um.createPost("Data Structures is fun #ds");

    //cout << "Post 0 created: " << p1 << endl;
    //cout << "Post 1 created: " << p2 << endl;

    //cout << "\n=== CHECK POSTS ===" << endl;
    //Post* post0 = um.getPost(0);
    //Post* post1 = um.getPost(1);

    //cout << "Post 0: " << (post0 ? "OK" : "NULL") << endl;
    //cout << "Post 1: " << (post1 ? "OK" : "NULL") << endl;

    //cout << "\n=== LOGIN reza ===" << endl;
    //um.login("reza", "123");
    //um.likePost(0);
    //um.likePost(1);

    //cout << "\n=== LOGIN sara ===" << endl;
    //um.login("sara", "123");
    //um.likePost(0);

    //cout << "\n=== DUPLICATE LIKE TEST ===" << endl;
    //um.likePost(0); // نباید دوباره حساب شود

    //cout << "\n=== FINAL LIKE COUNTS ===" << endl;
    //if (post0)
    //    cout << "Post 0 likes: " << post0->getLikeCount() << endl;

    //if (post1)
    //    cout << "Post 1 likes: " << post1->getLikeCount() << endl;

    //cout << "\n=== EXPECTED OUTPUT ===" << endl;
    //cout << "Post 0 likes: 2" << endl;
    //cout << "Post 1 likes: 1" << endl;

    //return 0;
    /*UserManager um;

    um.signup("ali", "123");
    um.signup("mmd", "123");
    um.login("ali", "123");
    um.login("mmd", "123");

    um.createPost("I love data structures");
    um.createPost("fhdfjfd data");
    um.createPost("Trie and inverted index are awesome");


    auto results = um.searchPosts("data");

    for (auto p : results) {
        cout << p->getAuthor() << " : " << p->getContent() << endl;
    }*/

    /*UserManager userManager;

    cout << "=== SIGNUP TEST ===" << endl;
    userManager.signup("amir", "123");
    userManager.signup("ali", "456");
    userManager.signup("reza", "789");

    cout << "Users created successfully.\n" << endl;
    cout << "\n=== POST TEST ===\n";
    userManager.login("amir", "123");

    userManager.createPost("Hello from amir!");
    userManager.createPost("Second post!");

    User* u = userManager.getUser("amir");
    for (int id : u->getPosts()) {
        Post* p = userManager.getPost(id);
        cout << p->getAuthor() << ": " << p->getContent() << endl;
    }*/

    /*cout << "=== LOGIN TEST ===" << endl;
    if (userManager.login("amir", "123")) {
        cout << "amir logged in.\n" << endl;
    }
    else {
        cout << "login failed.\n";
        return 0;
    }

    cout << "=== FOLLOW TEST ===" << endl;
    userManager.follow("ali");
    userManager.follow("reza");

    cout << "amir followed ali and reza.\n" << endl;

    cout << "Followers count:" << endl;
    cout << "ali followers: "
        << userManager.getUser("ali")->getFollowersCount() << endl;

    cout << "reza followers: "
        << userManager.getUser("reza")->getFollowersCount() << endl;

    cout << "\n=== UNFOLLOW TEST ===" << endl;
    userManager.unfollow("ali");

    cout << "amir unfollowed ali.\n" << endl;

    cout << "ali followers: "
        << userManager.getUser("ali")->getFollowersCount() << endl;

    userManager.logout();
    cout << "\nUser logged out." << endl;

    cout << "\n=== TEST FINISHED SUCCESSFULLY ===" << endl;
    return 0;*/
    /*return 0;
    Trie trie;

    trie.insert("amir");
    trie.insert("amin");
    trie.insert("ali");
    trie.insert("reza");

    std::string prefix = "a";
    auto users = trie.prefixSearch(prefix);

    for (auto& u : users)
        std::cout << u << std::endl;

    return 0;
    return 0;
    UserManager userManager;

    string line;

    cout << "ConnectGram started. Type commands:\n";

    while (true) {
        
        getline(cin, line);

        if (line.empty())
            continue;

        
        stringstream ss(line);
        string command;
        ss >> command;

   
        if (command == "exit") {
            cout << "Exiting ConnectGram...\n";
            break;
        }

    
        else if (command == "signup") {
            string username, password;
            ss >> username >> password;

            if (username.empty() || password.empty()) {
                cout << "Error: invalid signup command\n";
                continue;
            }

            if (userManager.signup(username, password)) {
                cout << "User registered successfully\n";
            }
            else {
                cout << "Error: username already exists\n";
            }
        }

      
        else if (command == "login") {
            string username, password;
            ss >> username >> password;

            if (userManager.login(username, password)) {
                cout << "Login successful\n";
            }
            else {
                cout << "Error: invalid username or password\n";
            }
        }

   
        else if (command == "logout") {
            if (userManager.getCurrentUser() == nullptr) {
                cout << "Error: no user is logged in\n";
            }
            else {
                userManager.logout();
                cout << "Logged out successfully\n";
            }
        }

       
        else {
            cout << "Error: unknown command\n";
        }
    }

    return 0;*/
    
}

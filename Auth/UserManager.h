#pragma once
#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <unordered_map>
#include <string>
#include "../Core/User.h"
#include "../Core/UserGraph.h"
#include "../Core/Post.h"
#include "../Search/InvertedIndex.h"

using namespace std;

class UserManager {
private:
    unordered_map<string, User*> users;
    User* currentUser;
    UserGraph graph;

    unordered_map<int, Post*> posts; // ✅ جدید
    int nextPostId=0;

    InvertedIndex invertedIndex;

public:
    UserManager();

    bool signup(const string& username, const string& password);

    bool login(const string& username, const string& password);

    void logout();

    bool follow(const string& username);
    bool unfollow(const string& username);

    // دسترسی
    User* getCurrentUser() const;
    User* getUser(const string& username) const;


    bool createPost(const string& content);
    Post* getPost(int postId);
    vector<Post*> searchPosts(const string& word);
    unordered_map<int, Post*>& getPosts();


    bool likePost(int postId);

    string smartSearchUser(const string& term);


    void showSearchHistory() const;


    ~UserManager();
};

#endif

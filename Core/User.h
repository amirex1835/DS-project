#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class User {
private:
    string username;
    string password;

    unordered_set<string> followers;
    unordered_set<string> following;

    vector<int> posts;

public:

    User(const string& username, const string& password);


    string getUsername() const;
    bool checkPassword(const string& inputPassword) const;


    void follow(const string& username);
    void unfollow(const string& username);

    int getFollowersCount() const;


    void addPost(int postId);
};

#endif

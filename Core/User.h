#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <unordered_set>
#include <vector>
#include "../History/SearchHistory.h"
using namespace std;
class User {
private:
    string username;
    string password;
    SearchHistory searchHistory;
    unordered_set<string> followers;
    unordered_set<string> following;

    vector<int> posts;


public:
    void addSearchHistory(const string& term);
    vector<string> getSearchHistory() const;

    User(const string& username, const string& password);


    string getUsername() const;
    bool checkPassword(const string& inputPassword) const;


    void follow(const string& username);
    void unfollow(const string& username);

    int getFollowersCount() const;

    void addFollower(const string& username);
    void removeFollower(const string& username);
    void addPost(int postId);
    const vector<int>& getPosts() const;

    const unordered_set<string>& getFollowing() const;
    const unordered_set<string>& getFollowers() const;


};

#endif

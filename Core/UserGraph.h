#pragma once
#pragma once
#ifndef USER_GRAPH_H
#define USER_GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class UserGraph {
private:
    // from -> list of users he follows
    unordered_map<string, vector<string>> adjList;

public:
    // افزودن یوزر به گراف
    void addUser(const string& username);

    // دنبال کردن
    void follow(const string& from, const string& to);

    // آنفالو
    void unfollow(const string& from, const string& to);

    // لیست افرادی که کاربر دنبال می‌کند
    vector<string> getFollowing(const string& username) const;
};

#endif

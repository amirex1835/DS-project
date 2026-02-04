#include "UserGraph.h"
#include <algorithm>

void UserGraph::addUser(const string& username) {
    if (adjList.find(username) == adjList.end()) {
        adjList[username] = vector<string>();
    }
}

void UserGraph::follow(const string& from, const string& to) {
    addUser(from);
    addUser(to);

    auto& list = adjList[from];

    // جلوگیری از follow تکراری
    if (find(list.begin(), list.end(), to) == list.end()) {
        list.push_back(to);
    }
}

void UserGraph::unfollow(const string& from, const string& to) {
    if (adjList.find(from) == adjList.end()) return;

    auto& list = adjList[from];
    list.erase(remove(list.begin(), list.end(), to), list.end());
}

vector<string> UserGraph::getFollowing(const string& username) const {
    if (adjList.find(username) == adjList.end())
        return {};

    return adjList.at(username);
}

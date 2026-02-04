#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
#include "../core/Post.h"
#include "../Core/User.h"

using namespace std;

struct FeedItem {
    Post* post;
    double score;

    bool operator<(const FeedItem& other) const {
        return score < other.score; // Max-Heap
    }
};

class FeedManager {
public:
    vector<Post*> getTopFeed(
        User* currentUser,
        unordered_map<int, Post*>& posts,
        unordered_map<string, User*>& users
    );
};

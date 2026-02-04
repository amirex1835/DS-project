#include "FeedManager.h"
#include <ctime>

vector<Post*> FeedManager::getTopFeed(
    User* currentUser,
    unordered_map<int, Post*>& posts,
    unordered_map<string, User*>& users
) {
    priority_queue<FeedItem> maxHeap;
    time_t now = time(nullptr);

    // لیست following کاربر فعلی
    const unordered_set<string>& following =
        currentUser->getFollowing();

    for (auto& entry : posts) {
        Post* post = entry.second;   // ✅ Post*

        const string& authorUsername = post->getAuthor();

        // ✅ بررسی فالو بودن بدون isFollowing
        if (following.count(authorUsername) == 0)
            continue;

        int likeCount = post->getLikeCount();

        double timeElapsed = difftime(now, post->getTimestamp());
        if (timeElapsed <= 0)
            timeElapsed = 1;

        int followersAuthor = 0;
        auto it = users.find(authorUsername);
        if (it != users.end()) {
            User* author = it->second;   // ✅ User*
            followersAuthor = author->getFollowers().size();
        }

        double score =
            (likeCount * 2) +
            (followersAuthor * 0.5) +
            (1000.0 / timeElapsed);

        maxHeap.push({ post, score });
    }

    vector<Post*> result;
    int k = 10;

    while (!maxHeap.empty() && k--) {
        result.push_back(maxHeap.top().post);
        maxHeap.pop();
    }

    return result;
}

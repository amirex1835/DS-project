#pragma once
#pragma once
#include <string>
#include <ctime>
#include <unordered_set>
using namespace std;

class Post {
private:
    int id;
    string author;
    string content;
    time_t timestamp;

    unordered_set <string> likedBy; // usernames
    int likeCount;

public:
    Post(int id, const string& author, const string& content);

    int getId() const;
    string getAuthor() const;
    string getContent() const;
    time_t getTimestamp() const;

    bool like(const string& username);
    int getLikeCount() const;
};

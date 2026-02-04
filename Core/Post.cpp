#include "Post.h"

Post::Post(int id, const string& author, const string& content)
{
    this->id = id;
    this->author = author;
    this->content = content;
    this->timestamp = time(nullptr);
    likeCount = 0;
}

int Post::getId() const {
    return id;
}

string Post::getAuthor() const {
    return author;
}

string Post::getContent() const {
    return content;
}

time_t Post::getTimestamp() const {
    return timestamp;
}

bool Post::like(const string& username)
{
    // جلوگیری از لایک تکراری
    if (likedBy.count(username))
        return false;

    likedBy.insert(username);
    likeCount++;
    return true;
}

int Post::getLikeCount() const
{
    return likeCount;
}

#include "User.h"

User::User(const string& username, const string& password)
{
	this->username = username;
	this->password = password;
}

string User::getUsername() const
{
	return username;
}

bool User::checkPassword(const string& inputPassword) const
{
	return password==inputPassword;
}

void User::follow(const string& username)
{
	following.insert(username);
}

void User::unfollow(const string& username)
{
	following.erase(username);
}

int User::getFollowersCount() const
{
	return followers.size();
}

void User::addPost(int postId)
{
	posts.push_back(postId);
}

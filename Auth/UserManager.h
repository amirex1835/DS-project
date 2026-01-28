#pragma once
#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <unordered_map>
#include <string>
#include "../Core/User.h"

using namespace std;

class UserManager {
private:
    unordered_map<string, User*> users;
    User* currentUser;

public:
    UserManager();

    bool signup(const string& username, const string& password);

    bool login(const string& username, const string& password);


    void logout();

    // دسترسی
    User* getCurrentUser() const;
    User* getUser(const string& username) const;


    ~UserManager();
};

#endif

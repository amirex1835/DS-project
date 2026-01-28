#include <iostream>
#include <sstream>
#include "Auth/UserManager.h"
#include "search/Trie.h"
using namespace std;

int main() {
    UserManager userManager;

    cout << "=== SIGNUP TEST ===" << endl;
    userManager.signup("amir", "123");
    userManager.signup("ali", "456");
    userManager.signup("reza", "789");

    cout << "Users created successfully.\n" << endl;

    cout << "=== LOGIN TEST ===" << endl;
    if (userManager.login("amir", "123")) {
        cout << "amir logged in.\n" << endl;
    }
    else {
        cout << "login failed.\n";
        return 0;
    }

    cout << "=== FOLLOW TEST ===" << endl;
    userManager.follow("ali");
    userManager.follow("reza");

    cout << "amir followed ali and reza.\n" << endl;

    cout << "Followers count:" << endl;
    cout << "ali followers: "
        << userManager.getUser("ali")->getFollowersCount() << endl;

    cout << "reza followers: "
        << userManager.getUser("reza")->getFollowersCount() << endl;

    cout << "\n=== UNFOLLOW TEST ===" << endl;
    userManager.unfollow("ali");

    cout << "amir unfollowed ali.\n" << endl;

    cout << "ali followers: "
        << userManager.getUser("ali")->getFollowersCount() << endl;

    userManager.logout();
    cout << "\nUser logged out." << endl;

    cout << "\n=== TEST FINISHED SUCCESSFULLY ===" << endl;
    return 0;
    /*return 0;
    Trie trie;

    trie.insert("amir");
    trie.insert("amin");
    trie.insert("ali");
    trie.insert("reza");

    std::string prefix = "a";
    auto users = trie.prefixSearch(prefix);

    for (auto& u : users)
        std::cout << u << std::endl;

    return 0;
    return 0;
    UserManager userManager;

    string line;

    cout << "ConnectGram started. Type commands:\n";

    while (true) {
        
        getline(cin, line);

        if (line.empty())
            continue;

        
        stringstream ss(line);
        string command;
        ss >> command;

   
        if (command == "exit") {
            cout << "Exiting ConnectGram...\n";
            break;
        }

    
        else if (command == "signup") {
            string username, password;
            ss >> username >> password;

            if (username.empty() || password.empty()) {
                cout << "Error: invalid signup command\n";
                continue;
            }

            if (userManager.signup(username, password)) {
                cout << "User registered successfully\n";
            }
            else {
                cout << "Error: username already exists\n";
            }
        }

      
        else if (command == "login") {
            string username, password;
            ss >> username >> password;

            if (userManager.login(username, password)) {
                cout << "Login successful\n";
            }
            else {
                cout << "Error: invalid username or password\n";
            }
        }

   
        else if (command == "logout") {
            if (userManager.getCurrentUser() == nullptr) {
                cout << "Error: no user is logged in\n";
            }
            else {
                userManager.logout();
                cout << "Logged out successfully\n";
            }
        }

       
        else {
            cout << "Error: unknown command\n";
        }
    }

    return 0;*/
}

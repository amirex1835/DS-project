#include <iostream>
#include <sstream>
#include "Auth/UserManager.h"

using namespace std;

int main() {
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

    return 0;
}

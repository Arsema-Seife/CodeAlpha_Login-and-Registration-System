#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Define a basic User struct
struct User {
    string username;
    string password;
};
   // Accept input username and passowrd
void registerUser() {
    User user;
    cout << "Enter User Name: ";
    cin >> user.username;
    cout << "Enter a Password: ";
    cin >> user.password;

    // Check for duplicate username
    ifstream infile("users.txt");
    string fileUsername, filePassword;
    bool exists = false;
    while (infile >> fileUsername >> filePassword) {
        if (fileUsername == user.username) {
            exists = true;
            break;
        }
    }
    infile.close();

    if (exists) {
        cout << "Error: User-Name already exists.\n";
    } else {
        ofstream outfile("users.txt", ios::app);
        outfile << user.username << " " << user.password << endl;
        outfile.close();
        cout << "Registration successful!\n";
    }
}

void loginUser() {
    User user;
    cout << "Enter your username: ";
    cin >> user.username;
    cout << "Enter your password: ";
    cin >> user.password;

    ifstream infile("users.txt");
    string fileUsername, filePassword;
    bool found = false;
    while (infile >> fileUsername >> filePassword) {
        if (fileUsername == user.username && filePassword == user.password) {
            found = true;
            break;
        }
    }
    infile.close();

    if (found) {
        cout << "Login successful!\n";
    } else {
        cout << "Error: Invalid User-name or password.\n";
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice.\n";
    }
    return 0;
}

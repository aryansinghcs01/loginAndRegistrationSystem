#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
const string DATABASE_FILE = "users_database.txt";

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string encryptDecrypt(const string& text) {
    char key = 'K'; // Simple key for XOR encryption
    string output = text;
    for (size_t i = 0; i < text.size(); ++i) {
        output[i] = text[i] ^ key;
    }
    return output;
}

bool checkUserExists(const string& username) {
    ifstream file(DATABASE_FILE);
    string storedUsername, storedPassword;

    if (file.is_open()) {
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username) {
                file.close();
                return true; // Duplicate found
            }
        }
        file.close();
    }
    return false; // No duplicate found
}
void registerUser() {
    string username, password;
    cout << "\n--- REGISTRATION ---\n";
    cout << "Enter a new username (no spaces): ";
    cin >> username;

    if (checkUserExists(username)) {
        cout << "[!] Error: Username '" << username << "' is already taken. Please try a different one.\n";
        return;
    }

    cout << "Enter a secure password (no spaces): ";
    cin >> password;

    ofstream file(DATABASE_FILE, ios::app);
    if (file.is_open()) {
        file << username << " " << encryptDecrypt(password) << "\n";
        file.close();
        cout << "[+] Registration successful! You can now log in.\n";
    } else {
        cout << "[!] Error: Could not open the database file for writing.\n";
    }
}

void loginUser() {
    string username, password, storedUsername, storedPassword;
    bool isLoginSuccessful = false;
    cout << "\n--- LOGIN ---\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file(DATABASE_FILE);
    if (file.is_open()) {
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username && encryptDecrypt(storedPassword) == password) {
                isLoginSuccessful = true;
                break;
            }
        }
        file.close();
    } else {
        cout << "[!] Error: Could not open the database file. Have you registered a user yet?\n";
        return;
    }
    if (isLoginSuccessful) {
        cout << "[+] Login successful! Welcome back, " << username << ".\n";
    } else {
        cout << "[!] Error: Invalid username or password. Please try again.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n====================================\n";
        cout << "   LOGIN AND REGISTRATION SYSTEM    \n";
        cout << "====================================\n";
        cout << " 1. Register a new account\n";
        cout << " 2. Login to an existing account\n";
        cout << " 3. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice (1-3): ";

        if (!(cin >> choice)) {
            cout << "[!] Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "[!] Invalid choice. Please select 1, 2, or 3.\n";
        }
    }
    return 0;
}
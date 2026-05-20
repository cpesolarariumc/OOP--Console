#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <thread>
#include <chrono>
#include "data.h"
#include "incremention.cpp"


using namespace std;

bool login(const string& username, const string& password) {
    ifstream infile("userdata.txt");
    string fileusername, filepassword;

   while (infile >> fileusername >> filepassword) {
        if (fileusername == username && filepassword == password) {
            return true;
        }
    }
    return false;
}
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}  
void registerUser(PlayerData& player) {
    int id = rand() % 100000; 
    player.generateIdentifierNumber(id);
    cout << "Registration successful! Your identifier number is: " << player.getIdentifiedNumber() << endl;
}
int main() {
    srand(static_cast<unsigned int>(time(0)));

    string username, password;
    int choice;

    cout << "Welcome to the Flower Game!" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        string newUsername, newPassword;
        cout << "Enter username: ";
        cin >> newUsername;
        cout << "Enter password: ";
        cin >> newPassword;
        ifstream infile("userdata.txt");
        string fileusername, filepassword;
        bool userExists = false;
        while (infile >> fileusername >> filepassword) {
            if (fileusername == newUsername) {
                userExists = true;
                break;
            }
        }
        if (userExists) {
            cout << "Username already exists. Please choose a different username." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            system("cls");
        } else {
            int id = rand() % 100000;
            ofstream outfile("userdata.txt", ios::app);
            outfile << newUsername << " " << newPassword << " " << id << " " << endl;
            for (int i = 0; i < 20 ; ++i) {
                cout << "Registering";
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                system("cls");
            }

            cout << "Registration successful!" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        system("cls");
    
    } else if (choice == 2) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (login(username, password)) {
            cout << "Login successful! Welcome, " << username << "!" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            system("cls");
        } else {
            cout << "Invalid username or password." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            system("cls");
        }
    } else {
        cout << "Invalid choice." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        system("cls");
    }
    


    return 0;
}

#ifndef MAIN_CPP
#define MAIN_CPP
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
#include "rose.cpp"
#include "Daisy.cpp"   
#include "sunflower.cpp"
#include "weather.cpp"
#include "game.cpp"
#include "careRandomize.cpp"
using namespace std;

bool login(const string& username, const string& password) {
    ifstream infile("userdata.txt");
    string fileusername, filepassword, fileId;
    while (infile >> fileusername >> filepassword >> fileId) {
        if (fileusername == username && filepassword == password) {
            return true;
        }
    }
    return false;
}

void registerUser(PlayerData& player) {
    int id = rand() % 100000; 
    player.generateIdentifierNumber(id);
    cout << "Registration successful! Your identifier number is: " << player.getIdentifiedNumber() << endl;
}
int main() {
    srand(static_cast<unsigned int>(time(0)));
    bool running=true;
    while (running){
        string username, password;
        int choice;
        outline();
        cout << "Welcome to the Flower Game!" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        outline();
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
                
            } else {
                int id = rand() % 100000;
                ofstream outfile("userdata.txt", ios::app);
                outfile << newUsername << " " << newPassword << " " << id << " " << endl;
                cout << "Registration successful!" << endl;
            }
            
        
        } else if (choice == 2) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

        if(login(username, password)) 
            {
                outline();
                cout << "Login successful! Welcome, " << username << "!" << endl;
                outline();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                cout << "Welcome to the Flower Game!" << endl;  
                
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                outline();
                cout << "1. Start Game" << endl;   
                cout << "2. Logout" << endl;
                outline();
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == 1) {
                    Start();
                }else{
                    cout << "Logging out.."<<endl;
                    main();
                };
            }
            else {
                cout << "Invalid username or password." << endl;
                outline();
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                
            }
        }
        else {
            outline();
            cout << "Invalid choice. Please try again." << endl;
            outline();
            main();
        }
    }
return 0;
}
#endif//MAIN_CPP
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
#include "playersdata.txt"
#include "incremention.cpp"
#include "rose.cpp"
#include "Daisy.cpp"   
#include "sunflower.cpp"
#include "weather.cpp"
#include "game.cpp"
#include "careRandomize.cpp"
using namespace std;
string newUsername,newPassword;
bool login(const string& username, const string& password, PlayerData& player) {
    ifstream infile("playersdata.txt");
    string fileusername, filepassword, fileId, fileFlowers;
    
    while (infile >> fileusername >> filepassword >> fileId >> fileFlowers) {
        if (fileusername.empty() || filepassword.empty() || fileId.empty() || fileFlowers.empty()) {
            continue; 
        }

        if (fileusername == username && filepassword == password) {
            player = PlayerData(fileusername, filepassword, fileId, fileFlowers);
            infile.close();
            return true;
        }
    }
    infile.close();
    return false;
}

void registerUser() {
    int id = rand() % 100000;
    
    ofstream outfile("playersdata.txt", ios::app);
    if (!outfile.is_open()) {
        cout << "\n [ERROR] Could not create or write to playersdata.txt!" << endl;
        cout << " Check if the file is locked or if your terminal is in the wrong folder.\n" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
        return;
    }
    outfile << newUsername << " " << newPassword << " " << id << " 0" << endl;
    outfile.close(); 
    cout << "                   Registration successful! Your identifier number is: " << id << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void Displayflowercount(const PlayerData& player){
    outline();
    cout << "                                 [ STATS ] " << player.getUsername() << "'s Flower Count: " << player.getFlowerCount() << endl;
    outline();
}

int main() {
    bool running=true;
    while (running){
        string username, password;
        int choice;
        outline();
        cout << "                                   Welcome to the Flower Game!" << endl;
        cout << "                                       [1]Register" << endl;
        cout << "                                       [2]Login" << endl;
        outline();
        cout << "                                     Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "                                   Enter username: ";
            cin >> newUsername;
            cout << "                                   Enter password: ";
            cin >> newPassword;
            ifstream infile("playersdata.txt");
            string fileusername, filepassword;
            bool userExists = false;
            while (infile >> fileusername >> filepassword) {
                if (fileusername == newUsername) {
                    userExists = true;
                    break;
                }
            }
            if (userExists) {
                cout << "                       Username already exists. Please choose a different username." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                
            } else {
                registerUser();
            }
            
        
        } else if (choice == 2) {
            cout << "                                   Enter username: ";
            cin >> username;
            cout << "                                   Enter password: ";
            cin >> password;

            PlayerData loggedInPlayer("", "", "");
        if(login(username, password,loggedInPlayer)) 
            {
                outline();
                cout << "                                Login successful! Welcome, " << username << "!" << endl;
                outline();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));

                bool loggedIn = true;
                while(loggedIn){
                    cout << "                                     Welcome to the Flower Game!" << endl;  
                    Displayflowercount(loggedInPlayer);
                    outline();
                    cout << "                                           [1] Start Game" << endl;   
                    cout << "                                           [2] Logout" << endl;
                    outline();
                   
                    outline();
                    cout << "                                         Enter your choice: ";
                    cin >> choice;
                    if (choice == 1) {
                        Start (loggedInPlayer);
                    }else{
                        cout << "                                         Logging out.."<<endl;
                        loggedIn=false;
                    }
                }
            }
            else {
                cout << "                                Invalid username or password." << endl;
                outline();
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                
            }
        }
        else {
            outline();
            cout << "                                   Invalid choice. Please try again." << endl;
            outline();
            main();
        }
    }
return 0;
}
#endif//MAIN_CPP
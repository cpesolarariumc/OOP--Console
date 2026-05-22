#ifndef careRandomize_H
#define careRandomize_H
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "incremention.cpp"
#include "main.cpp"
#include "game.cpp"
#include "close.cpp"
using namespace std;

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void careRandomize() {
    outline();
    cout << "                                    How would you like to care for your plant?" << endl;
    cout << "                                           [1] Water the plant" << endl;
    cout << "                                         [2] Fertilize the plant" << endl;
    cout << "                                           [3] Prune the plant" << endl;
    cout << "                                      [4] Give the plant some sunlight" << endl;
    cout << "                                             [5] Do nothing" << endl;
    outline();
    int care;
    cout << "                                            Enter your choice: ";
    cin >> care;
    switch (care) {
        case 1: {
            outline();
            cout << "                                            You watered the plant!" << endl;
            int result = rand() % 3;
            if (result == 0) {
                outline();
                cout << "                                  The plant loves the water and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            } else if (result == 1) {
                cout << "                                   The plant is overwatered and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(7000));
            } else {
                cout << "                                       The plant is underwatered and dies." << endl;
                outline();
                cout << "                                                     Game Over!" << endl;
                Close();
            }
        } break;
        case 2: {
            int result = rand() % 50;
            outline();
            cout << "                                         You fertilized the plant!" << endl;
            if (result <= 20) {
                outline();
                cout << "                                   The plant loves the fertilizer and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            } else if (result <= 35) {
                cout << "                                     The plant is over-fertilized and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(7000));
            } else {
                cout << "                                         The plant is under-fertilized and dies." << endl;
                outline();
                cout << "                                                      Game Over!" << endl;
                Close();
            }
            
        } 
        break;
        case 3: {
            outline();
            cout << "                                            You pruned the plant!" << endl;
            int result = rand() % 50;
            if (result <= 15) {
                outline();
                cout << "                                 The plant loves the pruning and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            } else if (result <= 35) {
                cout << "                                   The plant is over-pruned and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(7000));
            } else {
                cout << "                                        The plant is under-pruned and dies." << endl;
                outline();
                cout << "                                                      Game Over!" << endl;
                outline();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                Close();
            }
        } 
        break;
        case 4: {
            int result = rand() % 50;
            cout << "                                      You gave the plant some sunlight!" << endl;
            if (result <= 20) {
                outline();
                cout << "                                   The plant loves the sunlight and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            } else if (result <= 35) {
                cout << "                               The plant is overexposed to sunlight and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(7000));
            } else {
                cout << "                                   The plant is underexposed to sunlight and dies." << endl;
                outline();
                cout << "                                                          Game Over!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                Close();
            }
            
        } 
        break;

        case 5: {
            outline();
            cout << "                                         You did nothing to the plant!" << endl;
            int result = rand() % 50;
            if (result <= 45) { 
                outline();
                cout << "                                    The plant is doing fine without any care!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            } else {
                cout << "                                    The plant is neglected and dies." << endl;
                outline();
                cout << "                                           Game Over!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                Close();
            }
            
        }
        break;
        default:
            cout << "                               Invalid choice. Please try again." << endl;
            break;
    }

}
#endif
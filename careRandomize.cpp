#ifndef careRandomize_H
#define careRandomize_H
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "incremention.cpp"
using namespace std;

void careRandomize() {
   cout << "How would you like to care for your plant?" << endl;
    cout << "0. Water the plant" << endl;
    cout << "1. Fertilize the plant" << endl;
    cout << "2. Prune the plant" << endl;
    cout << "3. Give the plant some sunlight" << endl;
    int care;
    cout << "Enter your choice: ";
    cin >> care;
    switch (care) {
        case 0:
            cout << "You watered the plant!" << endl;
            if (rand() % 2 == 0) {
                outline();
                cout << "The plant loves the water and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else if (rand() % 2 == 0) {
                cout << "The plant is overwatered and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else {
                cout << "The plant is underwatered and dies." << endl;
                outline();
                cout << "Game Over!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                 break;
            }
            break;
        case 1:
            cout << "You fertilized the plant!" << endl;
            if (rand() % 2 == 0) {
                outline();
                cout << "The plant loves the fertilizer and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else if (rand() % 2 == 0) {
                cout << "The plant is over-fertilized and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else {
                cout << "The plant is under-fertilized and dies." << endl;
                outline();
                cout << "Game Over!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            }
        case 2:
            cout << "You pruned the plant!" << endl;
            if (rand() % 2 == 0) {
                outline();
                cout << "The plant loves the pruning and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else if (rand() % 2 == 0) {
                cout << "The plant is over-pruned and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else {
                cout << "The plant is under-pruned and dies." << endl;
                outline();
                cout << "Game Over!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            }
        case 3:
            cout << "You gave the plant some sunlight!" << endl;
            if (rand() % 2 == 0) {
                outline();
                cout << "The plant loves the sunlight and grows faster!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else if (rand() % 2 == 0) {
                cout << "The plant is overexposed to sunlight and grows slower." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            } else {
                cout << "The plant is underexposed to sunlight and dies." << endl;
                outline();
                cout << "Game Over!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

#endif
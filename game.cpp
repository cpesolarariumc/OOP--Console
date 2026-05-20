#ifndef GAME_H
#define GAME_H

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


void Start (){
int choice;
                cout << "Starting game..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                outline();
                 cout << "choose your flower" << endl;
                cout << "1. Rose" << endl;
                cout << "2. Daisy" << endl;
                cout << "3. Sunflower" << endl;
                outline();
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                 case 1:
                    cout << "You chose Rose!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    while (true) {
                        random_weather();
                        cout << "Rose is growing..." << endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        rose_stage1();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        rose_stage2();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        rose_stage3();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        rose_stage4();
                        random_weather(); 
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        rose_stage5();
                        outline();
                        cout << "Congratulations! Your Sunflower has fully grown!" << endl;
                        outline();

                        break;
                    }
                    break;
                 case 2:
                    cout << "You chose Daisy!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    while (true) {
                        random_weather();
                        cout << "Daisy is growing..." << endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        daisy_stage1();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        daisy_stage2();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        daisy_stage3();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        daisy_stage4();
                        random_weather(); 
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        daisy_stage5();
                        outline();
                        cout << "Congratulations! Your Daisy has fully grown!" << endl;
                        outline();
                        break; 
                    }
                   
                    break;
                 case 3:
                    cout << "You chose Sunflower!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    while (true) {
                        random_weather();
                        cout << "Sunflower is growing..." << endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        sunflower_stage1();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        sunflower_stage2();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        sunflower_stage3();
                        random_weather();
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        sunflower_stage4();
                        random_weather(); 
                        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
                        sunflower_stage5();
                        outline();
                        cout << "Congratulations! Your Sunflower has fully grown!" << endl;
                        outline();
                        break; 
                    }
                    
                    break;
                 default:
                    outline();
                    cout << "Invalid choice. Please try again." << endl;
                    outline();
                    Start();
                    break;
                }

}

#endif 
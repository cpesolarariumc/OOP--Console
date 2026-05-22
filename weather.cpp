#ifndef weather_H
#define weather_H
#include <iostream>
using namespace std;

void random_weather() {
    int weather = rand() % 4; 
    switch (weather) {
        case 0:
            cout << "                                            The weather is sunny." << endl;
            break;
        case 1:
            cout << "                                             It's raining." << endl;
            break;
        case 2:
            cout << "                                            The weather is cloudy." << endl;
            break;
        case 3:
            cout << "                                              It's snowing." << endl;
            break;
    }
}
#endif
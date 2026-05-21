#ifndef CLOSE_H
#define CLOSE_H
#include <iostream>
#include <string>
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
#include "main.cpp"
#include "careRandomize.cpp"
using namespace std;

void Close(){
 cout <<"Closing..." << endl;
 std::exit(EXIT_FAILURE);
}
#endif 
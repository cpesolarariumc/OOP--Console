#ifndef USERDATA_H
#define USERDATA_H
#include <string>
#include <cstdlib>
#include <iostream>

using std::string;
class PlayerData{
    private :
        string username;
        string password;
        string IdentifiedNumber;
        string flowercount;
    public :
   PlayerData (string u, string p , string i, string f = "0") 
    : username(u), password(p), IdentifiedNumber(i), flowercount(f) {}
    
    string getUsername() const {return username;}
    void setUsername(const string& u) {username = u;}

    void generateIdentifierNumber( int id) {IdentifiedNumber = std::to_string(rand() % 1000000);}

    int getIdentifiedNumber() const {
    if (IdentifiedNumber.empty()) return 0;
    return std::stoi(IdentifiedNumber);
    }

    int getFlowerCount() const { 
    if (flowercount.empty()) return 0;
    return std::stoi(flowercount); 
    }
    
    void incrementFlowerCount() {
            int count = getFlowerCount();
            count++;
            flowercount = std::to_string(count);
        }
};
#endif
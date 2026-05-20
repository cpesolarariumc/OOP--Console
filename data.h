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
    PlayerData (string u, string p , string i) : username(u), password(p), IdentifiedNumber(i), flowercount("0") {}
    string getUsername() const {return username;}
    void setUsername(const string& u) {username = u;}


    void generateIdentifierNumber( int id) {IdentifiedNumber = std::to_string(rand() % 1000000);}
    int getIdentifiedNumber() const {return std::stoi(IdentifiedNumber);}

    void incrementFlowerCount() {
        int count = std::stoi(flowercount);
        count++;
        flowercount = std::to_string(count);
    }
};
#endif
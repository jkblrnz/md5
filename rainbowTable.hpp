#ifndef RAINBOW_TABLE_H
#define RAINBOW_TABLE_H
#include <fstream>
#include <cmath>

class rainbowTable {
    public:
        rainbowTable();
        void loadDictionary();
        void loadTable();
        void crackPassword(std::string hashToCrack);
    private:
        //Data files
        std::fstream dictionary;
        static const int NUM_OF_PASSWORDS = 10; //Determines how many passwords will be taken from the dictionary
        static const int MAX_SALT = 1000; //This declaration limits any salt to three digits
        std::string table[NUM_OF_PASSWORDS][MAX_SALT]; //Probably uses far more memory than is necessary, but good for a test
        std::string passwords[NUM_OF_PASSWORDS];
};

#endif

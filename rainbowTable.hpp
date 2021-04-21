#ifndef RAINBOW_TABLE_H
#define RAINBOW_TABLE_H
#include <fstream>
#include <cmath>

class rainbowTable {
    private:
        static const int NUM_OF_PASSWORDS = 10; //Determines how many passwords will be taken from the dictionary
        static const int MAX_SALT = 1001; //This declaration limits any salt to three digits

        //Data files
        std::fstream dictionary;
        std::string table[NUM_OF_PASSWORDS][MAX_SALT]; //Probably uses far more memory than is necessary, but good for a test
        std::string passwords[NUM_OF_PASSWORDS];

    public:
        static const int MAX_PASSWORD_SIZE = 30;

        rainbowTable();
        void loadDictionary();
        void loadTable();
        void crackPassword(std::string hashToCrack);
        void salt(std::string &password, int s1, int s2, int s3, char rtrn[MAX_PASSWORD_SIZE], int &rtrn_size);
        bool is_equal(std::string str1, std::string str2);
};

#endif

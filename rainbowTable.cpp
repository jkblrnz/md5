#include <iostream>
#include "md5.hpp"
#include "rainbowTable.hpp"


//////////////////////////////////////////////////
//Function that is sent the password and three salt integers
//These are combined and "returned" via call by reference
//s1, s2, and s3 must all be single digits (in decimal)
//Call any time a password must be salted prior to use of md5
void rainbowTable::salt(std::string &password, int s1, int s2, int s3, char rtrn[MAX_PASSWORD_SIZE], int &rtrn_size)
{
    //Assign three salt characters to the end of the string
    char s;
    s = s1 + '0';
    password.append(1u, s);
    s = s2 + '0';
    password.append(1u, s);
    s = s3 + '0';
    password.append(1u, s);
    //Load into rtrn
    int length = password.length();
    rtrn_size = 0;
    for(int c = 0; c < length; c++)
    {
        rtrn[c] = password[c];
        rtrn_size++;
    }
}

/////////////////////////////////////////////////
//Function that is sent two strings and checks that they are equal
//Use to confirm multiple strings are the same
bool rainbowTable::is_equal(std::string str1, std::string str2)
{
    int length1 = str1.length(), length2 = str2.length();
    if(length1 != length2)
        return false;
    for(int c = 0; c < length1; c++)
    {
        if(str1[c] != str2[c])
            return false;
    }
    return true;
}

////////////////////////////////////////////////
//rainbowTable Constructor
rainbowTable::rainbowTable()
{
    dictionary.open("dictionary.txt");
    if(!dictionary.is_open())
        std::cout << "The dictionary file could not be found, expect heavy errors!";
}

///////////////////////////////////////////////
//Function to load passwords from the dictionary
//Call this before calling loadTable or crackPassword()
//This will return an error if the dictionary file does not contain enough passwords (NUM_OF_PASSWORDS)
void rainbowTable::loadDictionary()
{
    std::string temp;
    for(int c = 0; c < NUM_OF_PASSWORDS; c++)
    {
        dictionary >> temp;
        passwords[c] = temp;
    }
}

//////////////////////////////////////////////
//Function to load the entire table using the md5 class
//Do not call before loadDictionary(), call before calling crackPassword()
void rainbowTable::loadTable()
{
    std::string temp;
    double s1, s2, s3;
    char input[MAX_PASSWORD_SIZE];
    int a, input_size;
    for(int p = 0; p < NUM_OF_PASSWORDS; p++)
    {
        for(int s = 0; s < MAX_SALT; s++)
        {
            a = s;
            temp = passwords[p];
            //s1, s2, and s3 are assigned by poor programming etiquette, but this dirty process gets it done
            s1 = floor(a / 100);
            a = a % 100;
            s2 = floor(a/ 10);
            a = a % 10;
            s3 = a;
            salt(temp, s1, s2, s3, input, input_size);
            //Initialize and use md5 to hash
            md5 newMd5(temp);
            for(int i = 0; i < 1000; i++)
                newMd5 = md5(newMd5.toString());
            table[p][s] = newMd5.toString();
        }
    }
}

//////////////////////////////////////////////
//Function to run through the completed table and compare every hash until a match is found
//Do not call until loadDictionary() and loadTable() have been runtime_error
void rainbowTable::crackPassword(std::string hashToCrack)
{
    for(int p = 0; p < NUM_OF_PASSWORDS; p++)
    {
        for(int s = 0; s < MAX_SALT; s++)
        {
            if(is_equal(hashToCrack, table[p][s]))
            {
                std::cout << "We found a match! Is your password " << passwords[p] << " and your salt values " << s << "?\n";
            }
        }
    }
}

#include <iostream>
#include "md5.hpp"
#include "md5.cpp"
#include "rainbowTable.hpp"
#include "rainbowTable.cpp"


int main() {
    std::string test_password = "banana";
    int test_salt = 349; //Must be three digits (or less)
    std::cout << "PART 1: The password '" << test_password << "' will be salted with '" << test_salt << "' and hashed.\n";
    //////////////////////////////////////////////
    //Part 1: Take a password that is in the dictionary, salt it, and hash
    //////////////////////////////////////////////
    std::string hashedPassword1, password1 = test_password; //Consider implementing a method to randomly select one of the passwords in the dictionary for modularity
    char input[MAX_PASSWORD_SIZE];
    int input_size, s1, s2, s3, t;
    //Messy assignment of salt values
    t = test_salt;
    s1 = t / 100;
    t =  t % 100;
    s2 = t / 10;
    t = t % 10;
    s3 = t;
    //Salt it
    salt(password1, s1, s2, s3, input, input_size);
    md5 part1(password1);
    part1.update(input, input_size);
    part1.finalize();
    hashedPassword1 = part1.toString();
    std::cout << "The password has been hashed! It is: " << hashedPassword1 << "\n PART 2: The password will be hashed again to confirm it works.\n";
    //////////////////////////////////////////////
    //Part 2: Verify the hash by using the same password and salt, repeat the process, and check the two
    //////////////////////////////////////////////
    std::string hashedPassword2, password2 = test_password;
    char input2[MAX_PASSWORD_SIZE];
    int input_size2;
    salt(password2, s1, s2, s3, input2, input_size2); //s1, s2, and s3 should be unchanged, so reuse them
    md5 part2(password2);
    part2.update(input, input_size);
    part2.finalize();
    hashedPassword2 = part2.toString();
    if(is_equal(hashedPassword1, hashedPassword2))//is_equal function in rainbowTable.cpp, but not a class function
        std::cout << "A repeat hash with the same password and salt yielded the same hashed password.\n";
    //////////////////////////////////////////////
    //Part 3: Implement rainbowTable using the dictionary file and test every possible salt and password to crack it
    //////////////////////////////////////////////
    std::cout << "PART 3: Attempting to brute-force password and salt.\n";
    rainbowTable test;
    test.loadDictionary();
    test.loadTable();
    test.crackPassword(hashedPassword1);
}


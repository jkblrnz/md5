#include <iostream>
#include <string>
#include "rainbowTable.hpp"
#include "md5.hpp"

int main() {
    // normal example
    std::cout << "Offical:   " << "d41d8cd98f00b204e9800998ecf8427e" << '\n'; //rfc 1321
    std::cout << "Unsalted:  " << md5("").toString() << '\n'; // constructor example

    // salting example
    md5 tempMd5;
    std::string temp = "";
    std::string salt = "staticsalt0987612345";
    temp.append(salt);
    tempMd5.update(temp);
    tempMd5.finalize();
    std::cout << "Salted:    " << tempMd5.toString() << '\n';

    // slow md5
    for(int i = 0; i < 1000; i++)
        tempMd5 = md5(tempMd5.toString());
    std::cout << "slow md5:  " << tempMd5.toString() << '\n';

    return 0;
}


#include <iostream>
#include <string>
#include "rainbowTable.hpp"
#include "md5.hpp"

int main() {
    md5 newMd5("apple"),
        tempMd5;

    std::string temp = "grape";
    std::string salt = "staticsalt0987612345";
    temp.append(salt);
    tempMd5.update(temp.c_str(), temp.length());
    tempMd5.finalize();

    std::cout << md5("grape").toString() << '\n';
    std::cout << newMd5.toString() << '\n';
    std::cout << tempMd5.toString() << '\n';

    for(int i = 0; i < 1000; i++)
        tempMd5 = md5(tempMd5.toString());

    std::cout << tempMd5.toString() << '\n';

    return 0;
}


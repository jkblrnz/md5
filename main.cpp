#include <iostream>
#include "rainbowTable.hpp"
#include "md5.hpp"

int main() {
    md5 newMd5("apple");
    std::cout << md5("grape").toString() << '\n';
    std::cout << newMd5.toString() << '\n';
    return 0;
}


#include <iostream>
#include <string>
#include <chrono>
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

    auto start1 = std::chrono::high_resolution_clock::now();
    tempMd5.update(temp);
    tempMd5.finalize();
    auto finish1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(finish1 - start1);

    std::cout << "Salted:    " << tempMd5.toString() << " time(us): " << duration1.count() << '\n';

    // slow md5
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 1000 * 1000; i++)
        tempMd5 = md5(tempMd5.toString());
    auto finish2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(finish2 - start2);

    std::cout << "slow md5:  " << tempMd5.toString() << " time(us): " << duration2.count() << '\n';

    return 0;
}

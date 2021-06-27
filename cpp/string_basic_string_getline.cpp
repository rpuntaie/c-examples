/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_getline.exe ./cpp/string_basic_string_getline.cpp && (cd ../_build/cpp/;echo name|./string_basic_string_getline.exe)
https://en.cppreference.com/w/cpp/string/basic_string/getline
*/
#include <string>
#include <iostream>
#include <sstream>
int main()
{
    // greet the user
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << ", nice to meet you.\n";
    // read file line by line
    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    int sum = 0;
    for (std::string line; std::getline(input, line); ) {
        sum += std::stoi(line);
    }
    std::cout << "\nThe sum is: " << sum << "\n";
}


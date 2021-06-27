/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_stol.exe ./cpp/string_basic_string_stol.cpp && (cd ../_build/cpp/;./string_basic_string_stol.exe)
https://en.cppreference.com/w/cpp/string/basic_string/stol
*/
#include <iostream>
#include <string>
int main()
{
    std::string str1 = "45";
    std::string str2 = "3.14159";
    std::string str3 = "31337 with words";
    std::string str4 = "words and 2";
    int myint1 = std::stoi(str1);
    int myint2 = std::stoi(str2);
    int myint3 = std::stoi(str3);
    // error: 'std::invalid_argument'
    // int myint4 = std::stoi(str4);
    std::cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
    std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
    std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
    //std::cout << "std::stoi(\"" << str4 << "\") is " << myint4 << '\n';
}


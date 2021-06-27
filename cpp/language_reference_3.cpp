/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_reference_3.exe ./cpp/language_reference_3.cpp && (cd ../_build/cpp/;./language_reference_3.exe)
https://en.cppreference.com/w/cpp/language/reference
*/
#include <iostream>
#include <string>
char& char_number(std::string& s, std::size_t n) {
    return s.at(n); // string::at() returns a reference to char
}
int main() {
    std::string str = "Test";
    char_number(str, 1) = 'a'; // the function call is lvalue, can be assigned to
    std::cout << str << '\n';
}


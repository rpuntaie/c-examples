/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_reference_2.exe ./cpp/language_reference_2.cpp && (cd ../_build/cpp/;./language_reference_2.exe)
https://en.cppreference.com/w/cpp/language/reference
*/
#include <iostream>
#include <string>
void double_string(std::string& s) {
    s += s; // 's' is the same object as main()'s 'str'
}
int main() {
    std::string str = "Test";
    double_string(str);
    std::cout << str << '\n';
}


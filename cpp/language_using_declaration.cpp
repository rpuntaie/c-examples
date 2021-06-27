/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_using_declaration.exe ./cpp/language_using_declaration.cpp && (cd ../_build/cpp/;./language_using_declaration.exe)
https://en.cppreference.com/w/cpp/language/using_declaration
*/
#include <iostream>
#include <string>
using std::string;
int main()
{
    string str = "Example";
    using std::cout;
    cout << str;
}


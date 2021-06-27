/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_operator_ltltgtgt.exe ./cpp/string_basic_string_operator_ltltgtgt.cpp && (cd ../_build/cpp/;./string_basic_string_operator_ltltgtgt.exe)
https://en.cppreference.com/w/cpp/string/basic_string/operator_ltltgtgt
*/
#include <iostream>
#include <string>
#include <sstream>
int main()
{
    std::string greeting = "Hello, whirled!";
    std::istringstream is(greeting);
    std::string hello_comma;
    std::string whirled;
    is >> hello_comma;
    is >> whirled;
    std::cout << greeting << '\n';
    std::cout << hello_comma << '\n' << whirled << '\n';
}


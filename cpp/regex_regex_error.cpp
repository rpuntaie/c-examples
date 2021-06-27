/*
g++ --std=c++20 -pthread -o ../_build/cpp/regex_regex_error.exe ./cpp/regex_regex_error.cpp && (cd ../_build/cpp/;./regex_regex_error.exe)
https://en.cppreference.com/w/cpp/regex/regex_error
*/
#include <regex>
#include <iostream>
int main()
{
    try {
        std::regex re("[a-b][a");
    }
    catch (const std::regex_error& e) {
        std::cout << "regex_error caught: " << e.what() << '\n';
        if (e.code() == std::regex_constants::error_brack) {
            std::cout << "The code was error_brack\n";
        }
    }
}


/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_basic_string_erase.exe ./cpp/experimental_basic_string_erase.cpp && (cd ../_build/cpp/;./experimental_basic_string_erase.exe)
https://en.cppreference.com/w/cpp/experimental/basic_string/erase
*/
#include <experimental/string>
#include <iostream>
int main()
{
    std::string data{"$$P$A$S$S$$W$O$R$$D$"};
    std::cout << data << '\n';
    auto crack{'$'};
    std::experimental::erase(data, crack);
    std::cout << data << '\n';
}


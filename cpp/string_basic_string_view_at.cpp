/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_at.exe ./cpp/string_basic_string_view_at.cpp && (cd ../_build/cpp/;./string_basic_string_view_at.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/at
*/
#include <iostream>
#include <stdexcept>
#include <string_view>
int main()
{
    std::string_view str_view("abcdef");
    try {
        for (std::size_t i = 0; true; ++i)
            std::cout << i << ": " << str_view.at(i) << '\n';
    }
    catch (const std::out_of_range& e) {
        std::cout << "Whooops. Index is out of range.\n";
        std::cout << e.what() << '\n';
    }
}


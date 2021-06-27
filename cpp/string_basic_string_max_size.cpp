/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_max_size.exe ./cpp/string_basic_string_max_size.cpp && (cd ../_build/cpp/;./string_basic_string_max_size.exe)
https://en.cppreference.com/w/cpp/string/basic_string/max_size
*/
#include <iostream>
#include <string>
#include <climits>
int main()
{
    std::string s;
    std::cout << "Maximum size of a string is " << s.max_size()
              << " (pointer size: " << CHAR_BIT*sizeof(void*)
              << " bits)\n";
}


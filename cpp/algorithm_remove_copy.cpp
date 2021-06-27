/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_remove_copy.exe ./cpp/algorithm_remove_copy.cpp && (cd ../_build/cpp/;./algorithm_remove_copy.exe)
https://en.cppreference.com/w/cpp/algorithm/remove_copy
*/
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <iomanip>
int main()
{
    std::string str = "#Return #Value #Optimization";
    std::cout << "before: " << std::quoted(str) << "\n";
    std::cout << "after:  \"";
    std::remove_copy(str.begin(), str.end(),
                     std::ostream_iterator<char>(std::cout), '#');
    std::cout << "\"\n";
}


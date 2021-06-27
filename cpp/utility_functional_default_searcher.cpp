/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_default_searcher.exe ./cpp/utility_functional_default_searcher.cpp && (cd ../_build/cpp/;./utility_functional_default_searcher.exe)
https://en.cppreference.com/w/cpp/utility/functional/default_searcher
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
int main()
{
    std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
                     " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    std::string needle = "pisci";
    auto it = std::search(in.begin(), in.end(),
                   std::default_searcher(
                       needle.begin(), needle.end()));
    if(it != in.end())
        std::cout << "The string " << needle << " found at offset "
                  << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}


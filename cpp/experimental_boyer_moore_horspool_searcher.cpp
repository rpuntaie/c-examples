/*
g++ --std=c++20 -pthread -o ../_build/cpp/experimental_boyer_moore_horspool_searcher.exe ./cpp/experimental_boyer_moore_horspool_searcher.cpp && (cd ../_build/cpp/;./experimental_boyer_moore_horspool_searcher.exe)
https://en.cppreference.com/w/cpp/experimental/boyer_moore_horspool_searcher
*/
#include <iostream>
#include <string>
#include <experimental/algorithm>
#include <experimental/functional>
int main()
{
    std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
                     " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    std::string needle = "pisci";
    auto it = std::experimental::search(in.begin(), in.end(),
                   std::experimental::make_boyer_moore_horspool_searcher(
                       needle.begin(), needle.end()));
    if(it != in.end())
        std::cout << "The string " << needle << " found at offset "
                  << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}


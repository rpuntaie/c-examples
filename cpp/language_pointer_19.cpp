/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_19.exe ./cpp/language_pointer_19.cpp && (cd ../_build/cpp/;./language_pointer_19.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
int main()
{
    std::vector<std::string> v = {"a", "ab", "abc"};
    std::vector<std::size_t> l;
    transform(v.begin(), v.end(), std::back_inserter(l),
              std::mem_fn(&std::string::size));
    for(std::size_t n : l)
        std::cout << n << ' ';
}


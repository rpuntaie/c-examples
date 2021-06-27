/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_ostreambuf_iterator.exe ./cpp/iterator_ostreambuf_iterator.cpp && (cd ../_build/cpp/;./iterator_ostreambuf_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/ostreambuf_iterator
*/
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
int main()
{
    std::string s = "This is an example\n";
    std::copy(s.begin(), s.end(), std::ostreambuf_iterator<char>(std::cout));
}


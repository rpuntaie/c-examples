/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_ostream_iterator.exe ./cpp/iterator_ostream_iterator.cpp && (cd ../_build/cpp/;./iterator_ostream_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/ostream_iterator
*/
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
int main()
{
    std::istringstream str("0.1 0.2 0.3 0.4");
    std::partial_sum(std::istream_iterator<double>(str),
                      std::istream_iterator<double>(),
                      std::ostream_iterator<double>(std::cout, " "));
}


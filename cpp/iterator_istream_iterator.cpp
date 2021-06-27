/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_istream_iterator.exe ./cpp/iterator_istream_iterator.cpp && (cd ../_build/cpp/;./iterator_istream_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/istream_iterator
*/
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
int main()
{
    std::istringstream str("0.1 0.2 0.3 0.4");
    std::partial_sum(std::istream_iterator<double>(str),
                     std::istream_iterator<double>(),
                     std::ostream_iterator<double>(std::cout, " "));
    std::istringstream str2("1 3 5 7 8 9 10");
    std::cout << "\nThe first even number is " <<
        *std::find_if(std::istream_iterator<int>(str2),
                      std::istream_iterator<int>(),
                      [](int i){return i%2 == 0;})
        << ".\n";
    //" 9 10" left in the stream
}


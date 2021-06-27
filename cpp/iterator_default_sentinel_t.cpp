/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_default_sentinel_t.exe ./cpp/iterator_default_sentinel_t.cpp && (cd ../_build/cpp/;./iterator_default_sentinel_t.exe)
https://en.cppreference.com/w/cpp/iterator/default_sentinel_t
*/
#include <iterator>
#include <algorithm>
#include <list>
#include <iostream>
int main()
{
    std::list<int> l{3,1,4,1,5,9,2,6};
    std::ranges::copy(std::counted_iterator(std::begin(l), 4),
        std::default_sentinel, std::ostream_iterator<int>{std::cout, " "});
}


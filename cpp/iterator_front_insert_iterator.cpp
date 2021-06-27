/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_front_insert_iterator.exe ./cpp/iterator_front_insert_iterator.cpp && (cd ../_build/cpp/;./iterator_front_insert_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/front_insert_iterator
*/
#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>
int main()
{
    std::vector<int> v{1,2,3,4,5};
    std::deque<int> d;
    std::copy(v.begin(), v.end(),
              std::front_insert_iterator<std::deque<int>>(d)); // or std::front_inserter(d)
    for(int n : d)
        std::cout << n << ' ';
    std::cout << '\n';
}


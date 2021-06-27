/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multiset_empty.exe ./cpp/container_unordered_multiset_empty.cpp && (cd ../_build/cpp/;./container_unordered_multiset_empty.exe)
https://en.cppreference.com/w/cpp/container/unordered_multiset/empty
*/
#include <unordered_set>
#include <iostream>
int main()
{
    std::unordered_multiset<int> numbers;
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
    numbers.insert(42);
    numbers.insert(13317); 
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}


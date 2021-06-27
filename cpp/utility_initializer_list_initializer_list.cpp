/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_initializer_list_initializer_list.exe ./cpp/utility_initializer_list_initializer_list.cpp && (cd ../_build/cpp/;./utility_initializer_list_initializer_list.exe)
https://en.cppreference.com/w/cpp/utility/initializer_list/initializer_list
*/
#include <iostream>
#include <initializer_list>
int main() 
{
    std::initializer_list<int> empty_list;
    std::cout << "empty_list.size(): " << empty_list.size() << '\n';
    // create initializer lists using list-initialization
    std::initializer_list<int> digits {1, 2, 3, 4, 5};
    std::cout << "digits.size(): " << digits.size() << '\n';
    // special rule for auto means 'fractions' has the
    // type std::initializer_list<double>
    auto fractions = {3.14159, 2.71828};
    std::cout << "fractions.size(): " << fractions.size() << '\n';
}


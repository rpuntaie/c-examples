/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_end.exe ./cpp/string_basic_string_end.cpp && (cd ../_build/cpp/;./string_basic_string_end.exe)
https://en.cppreference.com/w/cpp/string/basic_string/end
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
int main()
{
    std::string s("Exemparl");
    std::next_permutation(s.begin(), s.end());
    std::string c;
    std::copy(s.cbegin(), s.cend(), std::back_inserter(c));
    std::cout << c <<'\n'; // "Exemplar"
}


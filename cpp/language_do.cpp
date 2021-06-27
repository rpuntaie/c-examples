/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_do.exe ./cpp/language_do.cpp && (cd ../_build/cpp/;./language_do.exe)
https://en.cppreference.com/w/cpp/language/do
*/
#include <iostream>
#include <algorithm>
#include <string>
int main()
{
    int j = 2;
    do { // compound statement is the loop body
        j += 2;
        std::cout << j << " ";
    } while (j < 9);
    std::cout << '\n';
    // common situation where do-while loop is used
    std::string s = "aba";
    std::sort(s.begin(), s.end());
    do std::cout << s << '\n'; // expression statement is the loop body
    while(std::next_permutation(s.begin(), s.end()));
}


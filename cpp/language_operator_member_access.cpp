/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_member_access.exe ./cpp/language_operator_member_access.cpp && (cd ../_build/cpp/;./language_operator_member_access.exe)
https://en.cppreference.com/w/cpp/language/operator_member_access
*/
#include <iostream>
#include <string>
#include <map>
int main()
{
    int a[4] = {1, 2, 3, 4};
    int* p = &a[2];
    std::cout << p[1] << p[-1] << 1[p] << (-1)[p] << '\n';
    std::map<std::pair<int, int>, std::string> m;
    m[{1, 2}] = "abc"; // uses the [{...}] version
}


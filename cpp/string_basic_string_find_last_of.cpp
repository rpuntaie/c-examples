/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_find_last_of.exe ./cpp/string_basic_string_find_last_of.cpp && (cd ../_build/cpp/;./string_basic_string_find_last_of.exe)
https://en.cppreference.com/w/cpp/string/basic_string/find_last_of
*/
#include<string>
#include<iostream>
int main()
{
    const std::string path="/root/config";
    auto const pos=path.find_last_of('/');
    const auto leaf=path.substr(pos+1);
    std::cout << leaf << '\n';
}


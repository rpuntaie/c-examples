/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_tuple_ignore.exe ./cpp/utility_tuple_ignore.cpp && (cd ../_build/cpp/;./utility_tuple_ignore.exe)
https://en.cppreference.com/w/cpp/utility/tuple/ignore
*/
#include <iostream>
#include <string>
#include <set>
#include <tuple>
int main()
{
    std::set<std::string> set_of_str;
    bool inserted = false;
    std::tie(std::ignore, inserted) = set_of_str.insert("Test");
    if (inserted) {
        std::cout << "Value was inserted successfully\n";
    }
}


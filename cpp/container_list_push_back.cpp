/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_push_back.exe ./cpp/container_list_push_back.cpp && (cd ../_build/cpp/;./container_list_push_back.exe)
https://en.cppreference.com/w/cpp/container/list/push_back
*/
#include <list>
#include <iostream>
#include <iomanip>
int main()
{
    std::list<std::string> letters;
    letters.push_back("abc");
    std::string s = "def";
    letters.push_back(std::move(s));
    std::cout << "list holds: ";
    for (auto&& i : letters) std::cout << std::quoted(i) << ' ';
    std::cout << "\nMoved-from string holds " << std::quoted(s) << '\n';
}


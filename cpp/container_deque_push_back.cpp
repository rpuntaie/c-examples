/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_push_back.exe ./cpp/container_deque_push_back.cpp && (cd ../_build/cpp/;./container_deque_push_back.exe)
https://en.cppreference.com/w/cpp/container/deque/push_back
*/
#include <deque>
#include <iostream>
#include <iomanip>
int main()
{
    std::deque<std::string> letters;
    letters.push_back("abc");
    std::string s = "def";
    letters.push_back(std::move(s));
    std::cout << "deque holds: ";
    for (auto&& i : letters) std::cout << std::quoted(i) << ' ';
    std::cout << "\nMoved-from string holds " << std::quoted(s) << '\n';
}


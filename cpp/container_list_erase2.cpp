/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_erase2.exe ./cpp/container_list_erase2.cpp && (cd ../_build/cpp/;./container_list_erase2.exe)
https://en.cppreference.com/w/cpp/container/list/erase2
*/
#include <iostream>
#include <numeric>
#include <string_view>
#include <list>
void print_container(std::string_view comment, const std::list<char>& c)
{
    std::cout << comment;
    for (auto x : c) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
int main()
{
    std::list<char> cnt(10);
    std::iota(cnt.begin(), cnt.end(), '0');
    print_container("Init:\n", cnt);
    std::erase(cnt, '3');
    print_container("Erase '3':\n", cnt);
    auto erased = std::erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; });
    print_container("Erase all even numbers:\n", cnt);
    std::cout << "In all " << erased << " even numbers were erased.\n";
}


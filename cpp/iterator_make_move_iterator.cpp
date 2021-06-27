/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_make_move_iterator.exe ./cpp/iterator_make_move_iterator.cpp && (cd ../_build/cpp/;./iterator_make_move_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/make_move_iterator
*/
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <string>
#include <iterator>
auto print = [](auto const rem, auto const& seq) {
    for (std::cout << rem; auto const& str : seq)
            std::cout << std::quoted(str) << ' ';
    std::cout << '\n';
};
int main()
{
    std::list<std::string> s{"one", "two", "three"};
    std::vector<std::string> v1(s.begin(), s.end()); // copy
    std::vector<std::string> v2(std::make_move_iterator(s.begin()),
                                std::make_move_iterator(s.end())); // move
    print("v1 now holds: ", v1);
    print("v2 now holds: ", v2);
    print("original list now holds: ", s);
}


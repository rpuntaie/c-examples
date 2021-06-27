/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_move_iterator.exe ./cpp/iterator_move_iterator.cpp && (cd ../_build/cpp/;./iterator_move_iterator.exe)
https://en.cppreference.com/w/cpp/iterator/move_iterator
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
int main()
{
    std::vector<std::string> v{"this", "_", "is", "_", "an", "_", "example"};
    auto print_v = [&](auto const rem) {
        std::cout << rem;
        for (const auto& s : v)
            std::cout << std::quoted(s) << ' ';
        std::cout << '\n';
    };
    print_v("Old contents of the vector: ");
    std::string concat = std::accumulate(std::make_move_iterator(v.begin()),
                                         std::make_move_iterator(v.end()),
                                         std::string());
    /* An alternative that uses std::move_iterator directly could be:
    using moviter_t = std::move_iterator<std::vector<std::string>::iterator>;
    std::string concat = std::accumulate(moviter_t(v.begin()),
                                         moviter_t(v.end()),
                                         std::string()); */
    print_v("New contents of the vector: ");
    std::cout << "Concatenated as string: " << quoted(concat) << '\n';
}


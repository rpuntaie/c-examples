/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_unreachable_sentinel_t.exe ./cpp/iterator_unreachable_sentinel_t.cpp && (cd ../_build/cpp/;./iterator_unreachable_sentinel_t.exe)
https://en.cppreference.com/w/cpp/iterator/unreachable_sentinel_t
*/
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <iostream>
template<class CharT>
std::size_t ntcts_len(const CharT *s)
{
    return std::ranges::find(s, std::unreachable_sentinel, CharT{}) - s;
}
int main()
{
    std::cout
        << ntcts_len("The quick brown fox jumps over the lazy dog.") << '\n';
}


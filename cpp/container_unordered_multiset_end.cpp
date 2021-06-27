/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multiset_end.exe ./cpp/container_unordered_multiset_end.cpp && (cd ../_build/cpp/;./container_unordered_multiset_end.exe)
https://en.cppreference.com/w/cpp/container/unordered_multiset/end
*/
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
int main() {
    const std::unordered_multiset<std::string> words = {
        "some", "words", "to", "count",
        "count", "these", "words"
    };
    for (auto it = words.begin(); it != words.end(); ) {
        auto cnt = words.count(*it);
        std::cout << *it << ":\t" << cnt << '\n';
        std::advance(it, cnt); // all cnt elements have equivalent keys
    }
}


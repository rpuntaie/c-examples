/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_multimap_begin.exe ./cpp/container_multimap_begin.cpp && (cd ../_build/cpp/;./container_multimap_begin.exe)
https://en.cppreference.com/w/cpp/container/multimap/begin
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <cstddef>
int main()
{
    auto show_node = [](const auto& node, char ending = '\n') {
        std::cout << "{ " << node.first << ", " << node.second << " }" << ending;
    };
    std::multimap<std::size_t, std::string> mmap;
    assert(mmap.begin() == mmap.end());   // OK
    assert(mmap.cbegin() == mmap.cend()); // OK
    mmap.insert({ sizeof(long), "LONG" });
    show_node(*(mmap.cbegin()));
    assert(mmap.begin() != mmap.end());   // OK
    assert(mmap.cbegin() != mmap.cend()); // OK
    mmap.begin()->second = "long";
    show_node(*(mmap.cbegin()));
    mmap.insert({ sizeof(int), "int" });
    show_node(*mmap.cbegin());
    mmap.insert({ sizeof(short), "short" });
    show_node(*mmap.cbegin());
    mmap.insert({ sizeof(char), "char" });
    show_node(*mmap.cbegin());
    mmap.insert({{ sizeof(float), "float" }, { sizeof(double), "double" }});
    std::cout << "mmap = { ";
    std::for_each(mmap.cbegin(), mmap.cend(), [&](const auto& n) { show_node(n, ' '); });
    std::cout << "};\n";
}


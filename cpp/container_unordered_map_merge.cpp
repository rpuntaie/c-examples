/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_merge.exe ./cpp/container_unordered_map_merge.cpp && (cd ../_build/cpp/;./container_unordered_map_merge.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/merge
*/
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
// print out a std::pair
template <class Os, class U, class V>
Os& operator<<(Os& os, const std::pair<U,V>& p) {
    return os << '{' << p.first << ", " << p.second << '}';
}
// print out an associative container
template <class Os, class K, class V>
Os& operator<<(Os& os, const std::unordered_map<K, V>& v) {
    os << '[' << v.size() << "] { ";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, "")) << e;
    return os << " }\n";
}
int main()
{
    std::unordered_map<std::string, int>
        p{ {"C", 3}, {"B", 2}, {"A", 1}, {"A", 0} },
        q{ {"E", 6}, {"E", 7}, {"D", 5}, {"A", 4} };
    std::cout << "p: " << p << "q: " << q;
    p.merge(q);
    std::cout << "p.merge(q);\n" << "p: " << p << "q: " << q;
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_merge.exe ./cpp/container_unordered_set_merge.cpp && (cd ../_build/cpp/;./container_unordered_set_merge.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/merge
*/
#include <iostream>
#include <unordered_set>
// print out a container
template <class Os, class K>
Os& operator<<(Os& os, const std::unordered_set<K>& v) {
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, " ")) << e;
    return os << " }\n";
}
int main()
{
    std::unordered_set<char>
        p{ 'C', 'B', 'B', 'A' }, 
        q{ 'E', 'D', 'E', 'C' };
    std::cout << "p: " << p << "q: " << q;
    p.merge(q);
    std::cout << "p.merge(q);\n" << "p: " << p << "q: " << q;
}


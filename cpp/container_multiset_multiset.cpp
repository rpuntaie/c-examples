/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_multiset_multiset.exe ./cpp/container_multiset_multiset.cpp && (cd ../_build/cpp/;./container_multiset_multiset.exe)
https://en.cppreference.com/w/cpp/container/multiset/multiset
*/
#include <iostream>
#include <string_view>
#include <set>
void print(const std::string_view name, const std::multiset<int>& ms)
{
    std::cout << name << ": ";
    for(auto element: ms)
        std::cout << element << " ";
    std::cout << '\n';
}
int main()
{
    // (1) Default constructor
    std::multiset<int> a;
    a.insert(4);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    print("a", a);
    // (2) Iterator constructor
    std::multiset<int> b(a.begin(), a.find(3));
    print("b", b);
    // (3) Copy constructor
    std::multiset<int> c(a);
    print("c", c);
    // (4) Move constructor
    std::multiset<int> d(std::move(a));
    print("d", d);
    // (5) Initializer list constructor
    std::multiset<int> e {3,2,1,2,4,7,3};
    print("e", e);
}


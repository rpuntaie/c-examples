/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_emplace.exe ./cpp/container_deque_emplace.cpp && (cd ../_build/cpp/;./container_deque_emplace.exe)
https://en.cppreference.com/w/cpp/container/deque/emplace
*/
#include <iostream>
#include <string>
#include <deque>
struct A {
    std::string s;
    A(std::string str) : s(std::move(str))  { std::cout << " constructed\n"; }
    A(const A& o) : s(o.s) { std::cout << " copy constructed\n"; }
    A(A&& o) : s(std::move(o.s)) { std::cout << " move constructed\n"; }
    A& operator=(const A& other) {
        s = other.s;
        std::cout << " copy assigned\n";
        return *this;
    }
    A& operator=(A&& other) {
        s = std::move(other.s);
        std::cout << " move assigned\n";
        return *this;
    }
};
int main()
{
    std::deque<A> container;
    std::cout << "construct 2 times A:\n";
    A two { "two" };
    A three { "three" };
    std::cout << "emplace:\n";
    container.emplace(container.end(), "one");
    std::cout << "emplace with A&:\n";
    container.emplace(container.end(), two);
    std::cout << "emplace with A&&:\n";
    container.emplace(container.end(), std::move(three));
    std::cout << "content:\n";
    for (const auto& obj : container)
        std::cout << ' ' << obj.s;
    std::cout << '\n';
}


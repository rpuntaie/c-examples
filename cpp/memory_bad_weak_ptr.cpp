/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_bad_weak_ptr.exe ./cpp/memory_bad_weak_ptr.cpp && (cd ../_build/cpp/;./memory_bad_weak_ptr.exe)
https://en.cppreference.com/w/cpp/memory/bad_weak_ptr
*/
#include <memory>
#include <iostream>
int main()
{
    std::shared_ptr<int> p1(new int(42));
    std::weak_ptr<int> wp(p1);
    p1.reset();
    try {
        std::shared_ptr<int> p2(wp);
    } catch(const std::bad_weak_ptr& e) {
        std::cout << e.what() << '\n';
    }
}


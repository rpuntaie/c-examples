/*
g++ --std=c++20 -pthread -o ../_build/cpp/atomic_atomic_is_lock_free.exe ./cpp/atomic_atomic_is_lock_free.cpp && (cd ../_build/cpp/;./atomic_atomic_is_lock_free.exe)
https://en.cppreference.com/w/cpp/atomic/atomic/is_lock_free
*/
#include <iostream>
#include <utility>
#include <atomic>
struct A { int a[100]; };
struct B { int x, y; };
int main()
{
    std::cout << std::boolalpha
              << "std::atomic<A> is lock free? "
              << std::atomic<A>{}.is_lock_free() << '\n'
              << "std::atomic<B> is lock free? "
              << std::atomic<B>{}.is_lock_free() << '\n';
}


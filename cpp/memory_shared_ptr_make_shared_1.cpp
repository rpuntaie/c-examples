/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_make_shared_1.exe ./cpp/memory_shared_ptr_make_shared_1.cpp && (cd ../_build/cpp/;./memory_shared_ptr_make_shared_1.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared
*/
#include <iostream>
#include <memory>
#include <type_traits>
struct C
{
  C(int i) : i(i) {} //< constructor needed (until C++20)
  int i;
};
int main()
{
    auto sp = std::make_shared<C>(12);
    static_assert(std::is_same_v<decltype(sp), std::shared_ptr<C>>);
    std::cout << sp->i << '\n';
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_get.exe ./cpp/memory_unique_ptr_get.cpp && (cd ../_build/cpp/;./memory_unique_ptr_get.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/get
*/
#include <iostream>
#include <string>
#include <memory>
int main()
{
    std::unique_ptr<std::string> s_p(new std::string("Hello, world!"));
    std::string *s = s_p.get();
    std::cout << *s << '\n';
}


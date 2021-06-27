/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_bad_cast.exe ./cpp/types_bad_cast.cpp && (cd ../_build/cpp/;./types_bad_cast.exe)
https://en.cppreference.com/w/cpp/types/bad_cast
*/
#include <iostream>
#include <typeinfo>
struct Foo { virtual ~Foo() {} };
struct Bar { virtual ~Bar() {} };
int main()
{
    Bar b;
    try {
        Foo& f = dynamic_cast<Foo&>(b);
    } catch(const std::bad_cast& e)
    {
        std::cout << e.what() << '\n';
    }
}


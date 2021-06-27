/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_declval.exe ./cpp/utility_declval.cpp && (cd ../_build/cpp/;./utility_declval.exe)
https://en.cppreference.com/w/cpp/utility/declval
*/
#include <utility>
#include <iostream>
struct Default { int foo() const { return 1; } };
struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};
int main()
{
    decltype(Default().foo()) n1 = 1;                   // type of n1 is int
//  decltype(NonDefault().foo()) n2 = n1;               // error: no default constructor
    decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n';
}


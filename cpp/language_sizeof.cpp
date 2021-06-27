/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_sizeof.exe ./cpp/language_sizeof.cpp && (cd ../_build/cpp/;./language_sizeof.exe)
https://en.cppreference.com/w/cpp/language/sizeof
*/
#include <iostream>
struct Empty {};
struct Base { int a; };
struct Derived : Base { int b; };
struct Bit { unsigned bit: 1; };
int main()
{
    Empty e;
    Derived d;
    Base& b = d;
    [[maybe_unused]] Bit bit;
    int a[10];
    std::cout 
      << "1) size of empty class:              " << sizeof e        << '\n'
      << "2) size of pointer:                  " << sizeof &e       << '\n'
//    << "3) size of function:                 " << sizeof(void())  << '\n' // error
//    << "4) size of incomplete type:          " << sizeof(int[])   << '\n' // error
//    << "5) size of bit field:                " << sizeof bit.bit  << '\n' // error
      << "6) size of Bit class:                " << sizeof(Bit)     << '\n'
      << "7) size of array of 10 int:          " << sizeof(int[10]) << '\n'
      << "8) size of array of 10 int (2):      " << sizeof a        << '\n'
      << "9) length of array of 10 int:        " << ((sizeof a) / (sizeof *a))   << '\n'
      << "A) length of array of 10 int (2):    " << ((sizeof a) / (sizeof a[0])) << '\n'
      << "B) size of the Derived:              " << sizeof d        << '\n'
      << "C) size of the Derived through Base: " << sizeof b        << '\n';
}


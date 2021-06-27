/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_basic_ostream_operator_ltlt.exe ./cpp/io_basic_ostream_operator_ltlt.cpp && (cd ../_build/cpp/;./io_basic_ostream_operator_ltlt.exe)
https://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt
*/
#include <iostream>
#include <iomanip>
#include <sstream>
int main()
{
    std::istringstream input(" \"Some text.\" ");
    volatile int n = 42;
    double f = 3.14;
    bool b = true;
    std::cout << n   // int overload
              << ' ' // non-member overload
              << std::boolalpha << b // bool overload
              << " " // non-member overload
              << std::fixed << f // double overload
              << input.rdbuf() // streambuf overload
              << &n // bool overload: volatile int* doesn't convert to const void*
              << std::endl; // function overload
}


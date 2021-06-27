/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_cin.exe ./cpp/io_cin.cpp && (cd ../_build/cpp/;echo 2|./io_cin.exe)
https://en.cppreference.com/w/cpp/io/cin
*/
#include <iostream>
struct Foo {
    int n;
    Foo() {
       std::cout << "Enter n: "; // no flush needed
       std::cin >> n;
    }
};
Foo f; // static object
int main()
{
    std::cout << "f.n is " << f.n << '\n';
}


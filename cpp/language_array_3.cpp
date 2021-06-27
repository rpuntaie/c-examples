/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_array_3.exe ./cpp/language_array_3.cpp && (cd ../_build/cpp/;./language_array_3.exe)
https://en.cppreference.com/w/cpp/language/array
*/
#include <iostream>
#include <numeric>
#include <iterator>
void g(int (&a)[3])
{
    std::cout << a[0] << '\n';
}
void f(int* p)
{
    std::cout << *p << '\n';
}
int main()
{
    int a[3] = {1, 2, 3};
    int* p = a;
    std::cout << sizeof a << '\n'  // prints size of array
              << sizeof p << '\n'; // prints size of a pointer
    // where arrays are acceptable, but pointers aren't, only arrays may be used
    g(a); // okay: function takes an array by reference
//  g(p); // error
    for(int n: a)              // okay: arrays can be used in range-for loops
        std::cout << n << ' '; // prints elements of the array
//  for(int n: p)              // error
//      std::cout << n << ' ';
    std::iota(std::begin(a), std::end(a), 7); // okay: begin and end take arrays
//  std::iota(std::begin(p), std::end(p), 7); // error
    // where pointers are acceptable, but arrays aren't, both may be used:
    f(a); // okay: function takes a pointer
    f(p); // okay: function takes a pointer
    std::cout << *a << '\n' // prints the first element
              << *p << '\n' // same
              << *(a + 1) << ' ' << a[1] << '\n'  // prints the second element
              << *(p + 1) << ' ' << p[1] << '\n'; // same
}


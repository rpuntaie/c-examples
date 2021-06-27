/*
g++ -std=c++20 -o ../_build/r/c1.exe r/c1.cpp && (cd ../_build/r;./c1.exe)
*/
// operator new[] example
#include <iostream>     // std::cout
#include <new>          // ::operator new[]

struct MyClass {
  int data;
  MyClass() {std::cout << '*';}  // print an asterisk for each construction
};

int main () {
  std::cout << "constructions (1): ";
  // allocates and constructs five objects:
  MyClass * p1 = new MyClass[5];
  std::cout << '\n';

  std::cout << "constructions (2): ";
  // allocates and constructs five objects (nothrow):
  MyClass * p2 = new (std::nothrow) MyClass[5];
  std::cout << '\n';

  delete[] p2;
  delete[] p1;

  return 0;
}

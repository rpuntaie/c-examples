/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_ub_12.exe ./cpp/language_ub_12.cpp
https://en.cppreference.com/w/cpp/language/ub
*/
#include <iostream>
int fermat() {
  const int MAX = 1000;
  int a=1,b=1,c=1;
  // Endless loop with no side effects is UB
  while (1) {
    if (((a*a*a) == ((b*b*b)+(c*c*c)))) return 1;
    a++;
    if (a>MAX) { a=1; b++; }
    if (b>MAX) { b=1; c++; }
    if (c>MAX) { c=1;}
  }
  return 0;
}
int main() {
  if (fermat())
    std::cout << "Fermat's Last Theorem has been disproved.\n";
  else
    std::cout << "Fermat's Last Theorem has not been disproved.\n";
}


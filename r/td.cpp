/*
g++ -std=c++20 -o ../_build/r/td.o -c r/td.cpp
*/

#include <concepts>

template<typename T>
concept integral_or_floating = std::integral<T> || std::floating_point<T>;

template<typename T>
concept integral_and_char = std::integral<T> && std::same_as<T, char>;

void f(std::integral auto){}        // #1
void f(integral_or_floating auto){} // #2
void f(std::same_as<char> auto){}   // #3

void w1() {

  // calls #1 because std::integral is more constrained
  // than integral_or_floating(#2)
  f(int{});
  // calls #2 because it's the only one whose constraint is satisfied
  f(double{});
  //// error, #1, #2 and #3's constraints are satisfied but unordered
  //// because std::same_as<char> appears only in #3
  //f(char{});
}


void f(integral_and_char auto){}    // #4

void w2() {
  // calls #4 because integral_and_char is more
  // constrained than std::same_as<char>(#3) and std::integral(#1)
  f(char{});
}

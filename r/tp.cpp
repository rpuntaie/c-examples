/*
g++ -std=c++20 -c r/tp.cpp
*/

#include <utility>

namespace my_lib {
enum class color { red, green, blue };
enum COLOR {RED, GREEN, BLUE};
enum class side {left, right};
}
void f(my_lib::color c1, my_lib::COLOR c2){

  using enum my_lib::color;   // introduce scoped enum
  using enum my_lib::COLOR;   // introduce unscoped enum
  using my_lib::side::left;   // introduce single enumerator id
  // C++17
  if(c1 == my_lib::color::red){/*...*/}
  // C++20
  if(c1 == green){/*...*/}
  if(c2 == BLUE){/*...*/}
  auto r = my_lib::side::right;   // qualified id is required for `right`
  auto l = left;                  // but not for `left`


  // before C++20
  int p0[]{1, 2, 3};
  int* p1 = new int[3]{1, 2, 3};  // explicit size is required
  // since C++20
  int* p2 = new int[]{1, 2, 3};
  int* p3 = new int[]{};  // empty
  char* p4 = new char[]{"hi"};
  // works with parenthesized initialization of aggregates
  int p5[](1, 2, 3);
  int* p6 = new int[](1, 2, 3);

}


template<typename T>
using IntPair = std::pair<int, T>;
void g(){
double d{};
IntPair<double> p0{1, d};   // C++17
IntPair p1{1, d};   // std::pair<int, double>
IntPair p2{1, p1};  // std::pair<int, std::pair<int, double>>
}



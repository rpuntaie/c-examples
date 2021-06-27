/*
g++ -std=c++20 -c r/tb.cpp
*/

#include <concepts>

template<typename T>
struct X{
   void f() requires std::integral<T>
   {}
};

void f(){
   X<double> x;
   ////error:
   //x.f();
   //auto pf = &X<double>::f;
}



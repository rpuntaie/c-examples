/*
g++ -std=c++20 -c r/te.cpp
*/

#include <concepts>

template<typename T>
requires std::is_integral_v<T>  // uses type traits instead of concepts
void f1(){}  // #1

template<typename T>
requires std::is_integral_v<T> || std::is_floating_point_v<T>
void f1(){}  // #2

//// error, #1 and #2 have common `std::is_integral_v<T>` expression
//// but at different locations(line 2 vs. line 6), thus, #1 and #2 constraints
//// are unordered and the call is ambiguous
//void w1(){
//    f1(int{});
//}

template<typename T>
concept C1 = requires{      // requires-expression is not decomposed
    requires std::integral<T>;
};

template<typename T>
concept C2 = requires{      // requires-expression is not decomposed
    requires (std::integral<T> || std::floating_point<T>);
};

void f2(C1 auto){}  // #3
void f2(C2 auto){}  // #4

//// error, since requires-expressions are not decomposed, #3 and #4 have
//// completely unrelated and hence unordered constraints and the call is
//// ambiguous
//void w1(){
//    f2(int{});
//}

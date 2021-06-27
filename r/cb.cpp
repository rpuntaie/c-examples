/*
g++ -std=c++20 -fmodules-ts -o ../_build/r/cb.exe r/cb.cpp && (cd ../_build/r;./cb.exe)
*/
#include <concepts>
#include <type_traits>

template <class T>
concept MyIntegral = std::is_integral_v<T>;
template<MyIntegral T>
bool ip(T a)
{
 return a > 0;
}



bool is_positive(std::integral auto a)
{
 return a > 0;
}
void b1()
{
 ip(2); // calls int version
 is_positive(2); // calls int version
 is_positive(3L); // calls long version
}

template<class T>
concept Equal = requires(T a, T b)
{
 { a == b } -> std::convertible_to<bool>;
 { a != b } -> std::convertible_to<bool>;
};
template<Equal T>
bool areEqual(T x, T y)
{
 return x == y;
}
void b2()
{
 areEqual(1, 1); // true
}

int main()
{
  b1();
  b2();
}

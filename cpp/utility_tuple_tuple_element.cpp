/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_tuple_tuple_element.exe ./cpp/utility_tuple_tuple_element.cpp && (cd ../_build/cpp/;./utility_tuple_tuple_element.exe)
https://en.cppreference.com/w/cpp/utility/tuple/tuple_element
*/
#include <iostream>
#include <tuple>
template <class... Args>
struct type_list
{
   template <std::size_t N>
   using type = typename std::tuple_element<N, std::tuple<Args...>>::type;
};
int main()
{
   std::cout << std::boolalpha;
   type_list<int, char, bool>::type<2> x = true;
   std::cout << x << '\n';
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_void_t_3.exe ./cpp/types_void_t_3.cpp && (cd ../_build/cpp/;./types_void_t_3.exe)
https://en.cppreference.com/w/cpp/types/void_t
*/
#include <iostream>
#include <type_traits>
#include <vector>
#include <map>
class A {};
template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin()),
                                  decltype(std::declval<T>().end())>>
    : std::true_type {};
// An iterator trait which value_type is always the value_type of the 
// iterated container, even with back_insert_iterator which value_type is void
template <typename T, typename = void>
struct iterator_trait 
: std::iterator_traits<T> {};
template <typename T>
struct iterator_trait<T, std::void_t<typename T::container_type>> 
: std::iterator_traits<typename T::container_type::iterator> {};
int main()
{
    std::cout << std::boolalpha;
    std::cout << is_iterable<std::vector<double>>::value << '\n';
    std::cout << is_iterable<std::map<int, double>>::value << '\n';
    std::cout << is_iterable<double>::value << '\n';
    std::cout << is_iterable<A>::value << '\n';
    std::vector<int> v;
    std::cout << std::is_same<iterator_trait<decltype(std::back_inserter(v))>::value_type
    , iterator_trait<decltype(v.cbegin())>::value_type >::value << '\n';
}


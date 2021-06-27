/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_remove_extent.exe ./cpp/types_remove_extent.cpp && (cd ../_build/cpp/;./types_remove_extent.exe)
https://en.cppreference.com/w/cpp/types/remove_extent
*/
#include <iostream>
#include <iterator>
#include <algorithm>
#include <type_traits>
template<class A>
typename std::enable_if< std::rank<A>::value == 1 >::type
print_1d(const A& a)
{
    copy(a, a+std::extent<A>::value,
         std::ostream_iterator<typename std::remove_extent<A>::type>(std::cout, " "));
    std::cout << '\n';
}
int main()
{
    int a[][3] = {{1,2,3},{4,5,6}};
//  print_1d(a); // compile-time error
    print_1d(a[1]);
}


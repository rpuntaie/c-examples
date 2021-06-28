/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_dependent_name_4.exe ./cpp/language_dependent_name_4.cpp && (cd ../_build/cpp/;./language_dependent_name_4.exe)
https://en.cppreference.com/w/cpp/language/dependent_name
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
// Bad idea: operator in global namespace, but its arguments are in std::
std::ostream& operator<<(std::ostream& os, std::pair<int, double> p)
{
    return os << p.first << ',' << p.second;
}
int main()
{
    typedef std::pair<int, double> elem_t;
    std::vector<elem_t> v(10);
    std::cout << v[0] << '\n'; // OK, ordinary lookup finds ::operator<<
    //// std::copy(v.begin(), v.end(),
    ////          std::ostream_iterator<elem_t>(std::cout, " ")); // Error: both ordinary 
    // lookup from the point of definition of std::ostream_iterator and ADL will 
    // only consider the std namespace, and will find many overloads of
    // std::operator<<, so the lookup will be done. Overload resolution will then
    // fail to find operator<< for elem_t in the set found by the lookup.
}


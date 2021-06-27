/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_tuple_forward_as_tuple.exe ./cpp/utility_tuple_forward_as_tuple.cpp && (cd ../_build/cpp/;./utility_tuple_forward_as_tuple.exe)
https://en.cppreference.com/w/cpp/utility/tuple/forward_as_tuple
*/
#include <iostream>
#include <map>
#include <tuple>
#include <string>
int main()
{
    std::map<int, std::string> m;
    m.emplace(std::piecewise_construct,
              std::forward_as_tuple(10),
              std::forward_as_tuple(20, 'a'));
    std::cout << "m[10] = " << m[10] << '\n';
    // The following is an error: it produces a
    // std::tuple<int&&, char&&> holding two dangling references.
    //
    // auto t = std::forward_as_tuple(20, 'a');
    // m.emplace(std::piecewise_construct, std::forward_as_tuple(10), t);
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_mem_fun_ref.exe ./cpp/utility_functional_mem_fun_ref.cpp && (cd ../_build/cpp/;./utility_functional_mem_fun_ref.exe)
https://en.cppreference.com/w/cpp/utility/functional/mem_fun_ref
*/
#include <functional>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
int main()
{
    std::vector<std::string> v = {"once", "upon", "a", "time"};
    std::transform(v.begin(), v.end(),
                   std::ostream_iterator<std::size_t>(std::cout, " "),
                   std::mem_fun_ref(&std::string::size));
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_deduction_guides.exe ./cpp/container_array_deduction_guides.cpp && (cd ../_build/cpp/;./container_array_deduction_guides.exe)
https://en.cppreference.com/w/cpp/container/array/deduction_guides
*/
#include <array>
int main()
{
    int const x = 10;
    std::array a{1, 2, 3, 5, x}; // OK, creates std::array<int, 5>
//  std::array b{1, 2u}; // Error, all arguments must have same type
}


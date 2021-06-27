/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_pair_deduction_guides.exe ./cpp/utility_pair_deduction_guides.cpp && (cd ../_build/cpp/;./utility_pair_deduction_guides.exe)
https://en.cppreference.com/w/cpp/utility/pair/deduction_guides
*/
#include <utility>
int main()
{
    int a[2], b[3];
    std::pair p{a, b}; // explicit deduction guide is used in this case
}


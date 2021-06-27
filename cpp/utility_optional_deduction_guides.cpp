/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_optional_deduction_guides.exe ./cpp/utility_optional_deduction_guides.cpp && (cd ../_build/cpp/;./utility_optional_deduction_guides.exe)
https://en.cppreference.com/w/cpp/utility/optional/deduction_guides
*/
#include <optional>
int main()
{
    int a[2];
    std::optional oa{a}; // explicit deduction guide is used in this case
}


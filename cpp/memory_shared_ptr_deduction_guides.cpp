/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_deduction_guides.exe ./cpp/memory_shared_ptr_deduction_guides.cpp && (cd ../_build/cpp/;./memory_shared_ptr_deduction_guides.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/deduction_guides
*/
#include <memory>
int main()
{
    auto p = std::make_shared<int>(42);
    std::weak_ptr w{p};    // explicit deduction guide is used in this case
    std::shared_ptr p2{w}; // explicit deduction guide is used in this case
}


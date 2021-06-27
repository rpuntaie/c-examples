/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_unique_ptr_operator_at.exe ./cpp/memory_unique_ptr_operator_at.cpp && (cd ../_build/cpp/;./memory_unique_ptr_operator_at.exe)
https://en.cppreference.com/w/cpp/memory/unique_ptr/operator_at
*/
#include <iostream>
#include <memory>
int main() 
{
    const int size = 10; 
    std::unique_ptr<int[]> fact(new int[size]);
    for (int i = 0; i < size; ++i) {
        fact[i] = (i == 0) ? 1 : i * fact[i-1];
    }
    for (int i = 0; i < size; ++i) {
        std::cout << i << "! = " << fact[i] << '\n';
    }
}


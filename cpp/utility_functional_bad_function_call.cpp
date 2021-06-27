/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_bad_function_call.exe ./cpp/utility_functional_bad_function_call.cpp && (cd ../_build/cpp/;./utility_functional_bad_function_call.exe)
https://en.cppreference.com/w/cpp/utility/functional/bad_function_call
*/
#include <iostream>
#include <functional>
int main()
{
    std::function<int()> f = nullptr;
    try {
        f();
    } catch(const std::bad_function_call& e) {
        std::cout << e.what() << '\n';
    }
}


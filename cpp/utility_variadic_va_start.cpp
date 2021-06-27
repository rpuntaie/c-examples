/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variadic_va_start.exe ./cpp/utility_variadic_va_start.cpp && (cd ../_build/cpp/;./utility_variadic_va_start.exe)
https://en.cppreference.com/w/cpp/utility/variadic/va_start
*/
#include <iostream>
#include <cstdarg>
int add_nums(int count, ...) 
{
    int result = 0;
    std::va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}
int main() 
{
    std::cout << add_nums(4, 25, 25, 50, 50) << '\n';
}


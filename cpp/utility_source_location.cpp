/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_source_location.exe ./cpp/utility_source_location.cpp && (cd ../_build/cpp/;./utility_source_location.exe)
https://en.cppreference.com/w/cpp/utility/source_location
*/
#include <iostream>
#include <string_view>
#include <source_location>
void log(const std::string_view message,
         const std::source_location location = 
               std::source_location::current())
{
    std::cout << "file: "
              << location.file_name() << "("
              << location.line() << ":"
              << location.column() << ") `"
              << location.function_name() << "`: "
              << message << '\n';
}
template <typename T> void fun(T x)
{
    log(x);
}
int main(int, char*[])
{
    log("Hello world!");
    fun("Hello C++20!");
}


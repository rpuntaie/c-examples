/*
g++ --std=c++20 -pthread -o ../_build/cpp/experimental_source_location.exe ./cpp/experimental_source_location.cpp && (cd ../_build/cpp/;./experimental_source_location.exe)
https://en.cppreference.com/w/cpp/experimental/source_location
*/
#include <iostream>
#include <string_view>
#include <experimental/source_location>
void log(const std::string_view& message, const std::experimental::source_location& location = std::experimental::source_location::current())
{
    std::cout << "info:"
              << location.file_name() << ":"
              << location.line() << " "
              << message << '\n';
}
int main()
{
    log("Hello world!");
}


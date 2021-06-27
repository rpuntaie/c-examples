/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_variant_npos.exe ./cpp/utility_variant_variant_npos.cpp && (cd ../_build/cpp/;./utility_variant_variant_npos.exe)
https://en.cppreference.com/w/cpp/utility/variant/variant_npos
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <variant>
struct Demon
{
    Demon(int) {}
    Demon(const Demon&) { throw std::domain_error("copy ctor"); }
    Demon& operator= (const Demon&) = default;
};
int main()
{
    std::variant<int, Demon> var{42};
    std::cout
        << std::boolalpha
        << "index == npos: " << (var.index() == std::variant_npos) << '\n';
    try { var = Demon{666}; } catch (const std::domain_error& ex)
    {
        std::cout
            << "Exception: " << ex.what() << '\n'
            << "index == npos: " << (var.index() == std::variant_npos) << '\n'
            << "valueless: " << var.valueless_by_exception() << '\n';
    }
}


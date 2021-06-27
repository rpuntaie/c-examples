/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_optional_swap2.exe ./cpp/utility_optional_swap2.cpp && (cd ../_build/cpp/;./utility_optional_swap2.exe)
https://en.cppreference.com/w/cpp/utility/optional/swap2
*/
#include <iostream>
#include <optional>
#include <string>
int main()
{
    std::optional<std::string> a{"██████"}, b{"▒▒▒▒▒▒"}; 
    auto print = [&](auto const& s) {
        std::cout 
            << s << "\t"
            << "a = " << a.value_or("(null)") << "  "
            << "b = " << b.value_or("(null)") << '\n';
    };
    print("Initially:");
    std::swap(a, b);
    print("swap(a, b):");
    a.reset();
    print("\n""a.reset():");
    std::swap(a, b);
    print("swap(a, b):");
}


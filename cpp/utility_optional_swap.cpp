/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_optional_swap.exe ./cpp/utility_optional_swap.cpp && (cd ../_build/cpp/;./utility_optional_swap.exe)
https://en.cppreference.com/w/cpp/utility/optional/swap
*/
#include <iostream>
#include <string>
#include <optional>
int main()
{
    std::optional<std::string> opt1("First example text");
    std::optional<std::string> opt2("2nd text");
    enum Swap { Before, After };
    auto print_opts = [&](Swap e) {
        std::cout << (e == Before ? "Before swap:\n" : "After swap:\n");
        std::cout << "opt1 contains '" << opt1.value_or("") << "'\n";
        std::cout << "opt2 contains '" << opt2.value_or("") << "'\n";
        std::cout << (e == Before ? "---SWAP---\n": "\n");
    };
    print_opts(Before);
    opt1.swap(opt2);
    print_opts(After);
    // Swap with only 1 set
    opt1 = "Lorem ipsum dolor sit amet, consectetur tincidunt.";
    opt2.reset();
    print_opts(Before);
    opt1.swap(opt2);
    print_opts(After);
}


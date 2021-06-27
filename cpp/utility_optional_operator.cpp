/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_optional_operator.exe ./cpp/utility_optional_operator.cpp && (cd ../_build/cpp/;./utility_optional_operator.exe)
https://en.cppreference.com/w/cpp/utility/optional/operator*
*/
#include <optional>
#include <iostream>
#include <string>
int main()
{
    using namespace std::string_literals;
    std::optional<int> opt1 = 1;
    std::cout<< "opt1: "  << *opt1 << '\n';
    *opt1 = 2;
    std::cout<< "opt1: "  << *opt1 << '\n';
    std::optional<std::string> opt2 = "abc"s;
    std::cout<< "opt2: " << *opt2 << " size: " << opt2->size() << '\n';
    // You can "take" the contained value by calling operator* on a rvalue to optional
    auto taken = *std::move(opt2);
    std::cout << "taken: " << taken << " opt2: " << *opt2 << "size: " << opt2->size()  << '\n';
}


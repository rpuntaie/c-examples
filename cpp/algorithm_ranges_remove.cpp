/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_remove.exe ./cpp/algorithm_ranges_remove.cpp && (cd ../_build/cpp/;./algorithm_ranges_remove.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/remove
*/
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
int main()
{
    std::string ndr{"N o _ D i a g n o s t i c _ R e q u i r e d"};
    std::cout << std::quoted(ndr) << " -> ";
    const auto ret1 = std::ranges::remove(ndr, ' ');
    ndr.erase(ret1.begin(), ret1.end());
    std::cout << std::quoted(ndr) << "\n\n";
    auto rm = [](char c) { return std::islower(c) or std::isspace(c); };
    std::string sfinae{"Substitution Failure Is Not An Error"};
    std::cout << std::quoted(sfinae) << " -> ";
    const auto ret2 = std::ranges::remove_if(sfinae, rm);
    sfinae.erase(ret2.begin(), ret2.end());
    std::cout << std::quoted(sfinae) << '\n';
}


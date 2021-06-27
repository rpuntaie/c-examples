/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_keys_view.exe ./cpp/ranges_keys_view.cpp && (cd ../_build/cpp/;./ranges_keys_view.exe)
https://en.cppreference.com/w/cpp/ranges/keys_view
*/
#include <iomanip>
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
int main()
{
    const std::vector<std::pair<std::string, double>> quark_mass{ // MeV/c²
        {"up", 2.3},      {"down", 4.8},
        {"charm", 1275},  {"strange", 95},
        {"top", 173'210}, {"bottom", 4'180},
    };
    std::cout << "quark name:  │ ";
    for (std::string const& name : std::views::keys(quark_mass))
        std::cout << std::setw(9) << name << " │ ";
    std::cout << "\n" "mass MeV/c²: │ ";
    for (const double mass : std::views::values(quark_mass))
        std::cout << std::setw(9) << mass << " │ ";
    std::cout << '\n';
}


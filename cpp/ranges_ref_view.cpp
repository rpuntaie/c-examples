/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_ref_view.exe ./cpp/ranges_ref_view.cpp && (cd ../_build/cpp/;./ranges_ref_view.exe)
https://en.cppreference.com/w/cpp/ranges/ref_view
*/
#include <ranges>
#include <iostream>
int main()
{
    const std::string s{"cosmos"};
    const std::ranges::take_view tv{s, 3};
    const std::ranges::ref_view rv{tv};
    std::cout
        << std::boolalpha
        << "call empty() : " << rv.empty() << '\n'
        << "call size()  : " << rv.size() << '\n'
        << "call begin() : " << *rv.begin() << '\n'
        << "call end()   : " << *(rv.end()-1) << '\n'
        << "call data()  : " << rv.data() << '\n'
        << "call base()  : " << rv.base().size() << '\n' // ~> tv.size()
        << "range-for    : ";
    for (const auto c: rv) { std::cout << c; }
    std::cout << '\n';
}


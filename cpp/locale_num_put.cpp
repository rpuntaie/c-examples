/*
g++ --std=c++20 -pthread -o ../_build/cpp/locale_num_put.exe ./cpp/locale_num_put.cpp && (cd ../_build/cpp/;./locale_num_put.exe) || true
https://en.cppreference.com/w/cpp/locale/num_put
*/
#include <iostream>
#include <locale>
#include <string>
#include <iterator>
int main()
{
    double n = 1234567.89;
    std::cout.imbue(std::locale("de_DE"));
    std::cout << "Direct conversion to string:\n"
              << std::to_string(n) << '\n'
              << "Output using a german locale:\n"
              << std::fixed << n << '\n'
              << "Output using an american locale:\n";
    // use the facet directly
    std::cout.imbue(std::locale("en_US.UTF-8"));
    auto& f = std::use_facet<std::num_put<char>>(std::cout.getloc());
    f.put(std::ostreambuf_iterator<char>(std::cout), std::cout, ' ', n);
    std::cout << '\n';
}


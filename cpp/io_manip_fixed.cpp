/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_fixed.exe ./cpp/io_manip_fixed.cpp && (cd ../_build/cpp/;./io_manip_fixed.exe)
https://en.cppreference.com/w/cpp/io/manip/fixed
*/
#include <iostream>
#include <iomanip>
#include <sstream>
enum class cap { title, middle, end };
void print(const char* text, double num, cap c)
{
    if (c == cap::title) std::cout <<
    "┌──────────┬────────────┬──────────────────────────┐\n"
    "│  number  │   iomanip  │      representation      │\n"
    "├──────────┼────────────┼──────────────────────────┤\n"
    ;
    std::cout << std::left
    << "│ " << std::setw(8) << text << " │ fixed      │ "
    << std::setw(24) << std::fixed        << num << " │\n"
    << "│ " << std::setw(8) << text << " │ scientific │ "
    << std::setw(24) << std::scientific   << num << " │\n"
    << "│ " << std::setw(8) << text << " │ hexfloat   │ "
    << std::setw(24) << std::hexfloat     << num << " │\n"
    << "│ " << std::setw(8) << text << " │ default    │ "
    << std::setw(24) << std::defaultfloat << num << " │\n"
    ;
    std::cout << (c != cap::end ?
    "├──────────┼────────────┼──────────────────────────┤\n" :
    "└──────────┴────────────┴──────────────────────────┘\n" );
}
int main()
{
    print("0.0", 0.0, cap::title);
    print("0.01", 0.01, cap::middle);
    print("0.00001", 0.00001, cap::end);
    double f;
    std::istringstream("0x1P-1022") >> std::hexfloat >> f;
    std::cout << "Parsing 0x1P-1022 as hex gives " << f << '\n';
}


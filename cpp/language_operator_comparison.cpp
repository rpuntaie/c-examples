/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_comparison.exe ./cpp/language_operator_comparison.cpp && (cd ../_build/cpp/;./language_operator_comparison.exe)
https://en.cppreference.com/w/cpp/language/operator_comparison
*/
#include <iostream>
int main()
{
    std::cout << std::boolalpha;
    int n = -1;
    int n2 = 1;
    std::cout << " -1 == 1? " << (n == n2) << '\n'
              << "Comparing two signed values:\n"
              << " -1  < 1? " << (n < n2) << '\n'
              << " -1  > 1? " << (n > n2) << '\n';
    unsigned int u = 1;
    std::cout << "Comparing signed and unsigned:\n"
              << " -1  < 1? " << (n < u) << '\n'
              << " -1  > 1? " << (n > u) << '\n';
    static_assert(sizeof(unsigned char) < sizeof(int),
                  "Can't compare signed and smaller unsigned properly");
    unsigned char uc = 1;
    std::cout << "Comparing signed and smaller unsigned:\n"
              << " -1  < 1? " << (n < uc) << '\n'
              << " -1  > 1? " << (n > uc) << '\n';
}


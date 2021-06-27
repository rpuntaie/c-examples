/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_other_1.exe ./cpp/language_operator_other_1.cpp && (cd ../_build/cpp/;./language_operator_other_1.exe)
https://en.cppreference.com/w/cpp/language/operator_other
*/
#include <iostream>
int main()
{
    int n = 1;
    int m = (++n, std::cout << "n = " << n << '\n', ++n, 2*n);
    std::cout << "m = " << (++m, m) << '\n';
}


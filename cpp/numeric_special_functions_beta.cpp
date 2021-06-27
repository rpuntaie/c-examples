/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_special_functions_beta.exe ./cpp/numeric_special_functions_beta.cpp && (cd ../_build/cpp/;./numeric_special_functions_beta.exe)
https://en.cppreference.com/w/cpp/numeric/special_functions/beta
*/
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
double binom(int n, int k) { return 1/((n+1)*std::beta(n-k+1,k+1)); }
int main()
{
    std::cout << "Pascal's triangle:\n";
    for(int n = 1; n < 10; ++n) {
        std::cout << std::string(20-n*2, ' ');
        for(int k = 1; k < n; ++k)
            std::cout << std::setw(3) << binom(n,k) << ' ';
        std::cout << '\n';
    }
}


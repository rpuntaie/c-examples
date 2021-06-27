/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_constant_evaluated_1.exe ./cpp/types_is_constant_evaluated_1.cpp && (cd ../_build/cpp/;./types_is_constant_evaluated_1.exe)
https://en.cppreference.com/w/cpp/types/is_constant_evaluated
*/
#include <type_traits>
#include <cmath>
#include <iostream>
constexpr double power(double b, int x)
{
    if (std::is_constant_evaluated() && !(b == 0.0 && x < 0)) {
        // A constant-evaluation context: Use a constexpr-friendly algorithm.
        if (x == 0)
            return 1.0;
        double r = 1.0, p = x > 0 ? b : 1.0 / b;
        auto u = unsigned(x > 0 ? x : -x);
        while (u != 0) {
            if (u & 1) r *= p;
            u /= 2;
            p *= p;
        }
        return r;
    } else {
        // Let the code generator figure it out.
        return std::pow(b, double(x));
    }
}
int main()
{
    // A constant-expression context
    constexpr double kilo = power(10.0, 3);
    int n = 3;
    // Not a constant expression, because n cannot be converted to an rvalue
    // in a constant-expression context
    // Equivalent to std::pow(10.0, double(n))
    double mucho = power(10.0, n);
    std::cout << kilo << " " << mucho << "\n"; // (3)
}


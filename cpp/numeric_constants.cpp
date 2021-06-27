/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_constants.exe ./cpp/numeric_constants.cpp && (cd ../_build/cpp/;./numeric_constants.exe)
https://en.cppreference.com/w/cpp/numeric/constants
*/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>
#include <string_view>
struct two_t {};
template <class T>
constexpr auto operator^(T base, two_t) { return base * base; }
int main()
{
    using namespace std::numbers;
    constexpr two_t ²;
    std::cout << "The answer is " <<
        (((std::sin(e)^²) + (std::cos(e)^²)) + 
        std::pow(e, ln2) + std::sqrt(pi) * inv_sqrtpi +
        ((std::cosh(pi)^²) - (std::sinh(pi)^²)) +
        sqrt3 * inv_sqrt3 * log2e * ln2 * log10e * ln10 *
        pi * inv_pi + (phi * phi - phi)) *
        ((sqrt2 * sqrt3)^²) << '\n';
    auto egamma_aprox = [] (unsigned const iterations) {
        long double s = 0, m = 2.0;
        for (unsigned c = 2; c != iterations; ++c, ++m) {
            const long double t = std::riemann_zeta(m) / m;
            (c & 1) == 0 ? s += t : s -= t;
        }
        return s;
    };
    constexpr std::string_view γ {"0.577215664901532860606512090082402"};
    std::cout 
        << "γ as 10⁶ sums of ±ζ(m)/m   = "
        << egamma_aprox(1'000'000) << '\n'
        << "γ as egamma_v<float>       = "
        << std::setprecision(std::numeric_limits<float>::digits10 + 1)
        << egamma_v<float> << '\n'
        << "γ as egamma_v<double>      = "
        << std::setprecision(std::numeric_limits<double>::digits10 + 1)
        << egamma_v<double> << '\n'
        << "γ as egamma_v<long double> = "
        << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
        << egamma_v<long double> << '\n'
        << "γ with " << γ.length() - 1 << " digits precision = " << γ << '\n';
}


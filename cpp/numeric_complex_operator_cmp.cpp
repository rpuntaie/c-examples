/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_complex_operator_cmp.exe ./cpp/numeric_complex_operator_cmp.cpp && (cd ../_build/cpp/;./numeric_complex_operator_cmp.exe)
https://en.cppreference.com/w/cpp/numeric/complex/operator_cmp
*/
#include <complex>
int main()
{
    using std::operator""i; // or: using namespace std::complex_literals;
    static_assert(1.0i == 1.0i);
    static_assert(2.0i != 1.0i);
    constexpr std::complex z(1.0, 0.0);
    static_assert(z == 1.0);
    static_assert(1.0 == z);
    static_assert(2.0 != z);
    static_assert(z != 2.0);
}


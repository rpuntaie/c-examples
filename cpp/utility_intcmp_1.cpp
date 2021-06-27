/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_intcmp_1.exe ./cpp/utility_intcmp_1.cpp && (cd ../_build/cpp/;./utility_intcmp_1.exe)
https://en.cppreference.com/w/cpp/utility/intcmp
*/
#include <utility>
int main()
{
    static_assert( sizeof(int) == 4 ); // precondition
    // Quite surprisingly
    static_assert( -1 > 1U );
    // because after implicit conversion of -1 to the RHS type (`unsigned int`)
    // the expression is equivalent to:
    static_assert( 0xFFFFFFFFU > 1U );
    static_assert( 0xFFFFFFFFU == static_cast<unsigned>(-1) );
    // In contrast, the cmp_* family compares integers as most expected -
    // negative signed integers always compare less than unsigned integers:
    static_assert( std::cmp_less( -1, 1U ) );
    static_assert( std::cmp_less_equal( -1, 1U ) );
    static_assert( ! std::cmp_greater( -1, 1U ) );
    static_assert( ! std::cmp_greater_equal( -1, 1U ) );
}


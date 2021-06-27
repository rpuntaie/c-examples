/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_invocable.exe ./cpp/types_is_invocable.cpp && (cd ../_build/cpp/;./types_is_invocable.exe)
https://en.cppreference.com/w/cpp/types/is_invocable
*/
#include <type_traits>
auto func2(char) -> int (*)()
{
    return nullptr;
}
int main()
{
    static_assert( std::is_invocable_v<int()> );
    static_assert( not std::is_invocable_v<int(), int> );
    static_assert( std::is_invocable_r_v<int, int()> );
    static_assert( not std::is_invocable_r_v<int*, int()> );
    static_assert( std::is_invocable_r_v<void, void(int), int> );
    static_assert( not std::is_invocable_r_v<void, void(int), void> );
    static_assert( std::is_invocable_r_v<int(*)(), decltype(func2), char> );
    static_assert( not std::is_invocable_r_v<int(*)(), decltype(func2), void> );
}


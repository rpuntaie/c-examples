/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_reserve.exe ./cpp/string_basic_string_reserve.cpp && (cd ../_build/cpp/;./string_basic_string_reserve.exe)
https://en.cppreference.com/w/cpp/string/basic_string/reserve
*/
#include <cassert>
#include <string>
int main()
{
    std::string s;
    std::string::size_type new_capacity{ 100u };
    assert(new_capacity > s.capacity());
    s.reserve(new_capacity);
    assert(new_capacity <= s.capacity());
}


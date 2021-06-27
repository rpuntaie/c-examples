/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_clear.exe ./cpp/string_basic_string_clear.cpp && (cd ../_build/cpp/;./string_basic_string_clear.exe)
https://en.cppreference.com/w/cpp/string/basic_string/clear
*/
#include <cassert>
#include <string>
int main()
{
    std::string s{ "Exemplar" };
    std::string::size_type const capacity = s.capacity();
    s.clear();
    assert(s.capacity() == capacity);
    assert(s.empty());
    assert(s.size() == 0);
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_basic_string_view.exe ./cpp/string_basic_string_view_basic_string_view.cpp && (cd ../_build/cpp/;./string_basic_string_view_basic_string_view.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/basic_string_view
*/
#include <array>
#include <iostream>
#include <string>
#include <string_view>
int main()
{
    constexpr std::wstring_view wcstr_v = L"xyzzy";
    char array[3] = {'B', 'a', 'r'};
    std::string_view array_v(array, std::size(array));
    std::string cppstr = "Foo";
    std::string_view cppstr_v(cppstr);
    std::array ar = {'P', 'u', 'b'};
    std::string_view ar_v(ar.begin(), ar.end()); // C++20
    std::cout << cppstr_v << ' '
              << array_v << ' '
              << ar_v << ' '
              << wcstr_v.size() << '\n';
}


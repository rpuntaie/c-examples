/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_remove_suffix.exe ./cpp/string_basic_string_view_remove_suffix.cpp && (cd ../_build/cpp/;./string_basic_string_view_remove_suffix.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/remove_suffix
*/
#include <iostream>
#include <string_view>
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', '\0', '\0', '\0'};
    std::string_view v(arr, sizeof arr);
    auto trim_pos = v.find('\0');
    if(trim_pos != v.npos)
        v.remove_suffix(v.size() - trim_pos);
    std::cout << "Array: '" << arr << "', size=" << sizeof arr << '\n'
              << "View : '" << v << "', size=" << v.size() << '\n';
}


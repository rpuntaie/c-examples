/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_capacity.exe ./cpp/string_basic_string_capacity.cpp && (cd ../_build/cpp/;./string_basic_string_capacity.exe)
https://en.cppreference.com/w/cpp/string/basic_string/capacity
*/
#include <iostream>
#include <string>
void show_capacity(std::string const& s)
{
    std::cout << "'" << s << "' has capacity " << s.capacity() << ".\n";
}
int main()
{
    std::string s{"Exemplar"};
    show_capacity(s);
    s += " is an example string.";
    show_capacity(s);
}


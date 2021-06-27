/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_empty.exe ./cpp/string_basic_string_empty.cpp && (cd ../_build/cpp/;./string_basic_string_empty.exe)
https://en.cppreference.com/w/cpp/string/basic_string/empty
*/
#include <iostream>
#include <string>
int main()
{
    std::string s;
    std::boolalpha(std::cout);
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";
    s = "Exemplar";
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";
    s = "";
    std::cout << "s.empty():" << s.empty() << "\t s:'" << s << "'\n";
}


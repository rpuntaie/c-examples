/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_find.exe ./cpp/string_basic_string_find.cpp && (cd ../_build/cpp/;./string_basic_string_find.exe)
https://en.cppreference.com/w/cpp/string/basic_string/find
*/
#include <string>
#include <iostream>
void print(std::string::size_type n, std::string const &s)
{
    if (n == std::string::npos) {
        std::cout << "not found\n";
    } else {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}
int main()
{
    std::string::size_type n;
    std::string const s = "This is a string";
    // search from beginning of string
    n = s.find("is");
    print(n, s);
    // search from position 5
    n = s.find("is", 5);
    print(n, s);
    // find a single character
    n = s.find('a');
    print(n, s);
    // find a single character
    n = s.find('q');
    print(n, s);
}


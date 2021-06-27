/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_reference_1.exe ./cpp/language_reference_1.cpp && (cd ../_build/cpp/;./language_reference_1.exe)
https://en.cppreference.com/w/cpp/language/reference
*/
#include <iostream>
#include <string>
int main() {
    std::string s = "Ex";
    std::string& r1 = s;
    const std::string& r2 = s;
    r1 += "ample";           // modifies s
//  r2 += "!";               // error: cannot modify through reference to const
    std::cout << r2 << '\n'; // prints s, which now holds "Example"
}


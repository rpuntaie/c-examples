/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_functiontryblock.exe ./cpp/language_functiontryblock.cpp && (cd ../_build/cpp/;./language_functiontryblock.exe)
https://en.cppreference.com/w/cpp/language/function-try-block
*/
#include <iostream>
#include <string>
struct S {
    std::string m;
    S(const std::string& str, int idx) try : m(str, idx) {
        std::cout << "S(" << str << ", " << idx << ") constructed, m = " << m << '\n';
    } catch(const std::exception& e) {
        std::cout << "S(" << str << ", " << idx << ") failed: " << e.what() << '\n';
    } // implicit "throw;" here
};
int main() {
    S s1{"ABC", 1}; // does not throw (index is in bounds)
    try {
        S s2{"ABC", 4}; // throws (out of bounds)
    } catch (std::exception& e) {
        std::cout << "S s2... raised an exception: " << e.what() << '\n';
    }
}


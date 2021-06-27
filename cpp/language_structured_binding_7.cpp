/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_structured_binding_7.exe ./cpp/language_structured_binding_7.cpp && (cd ../_build/cpp/;./language_structured_binding_7.exe)
https://en.cppreference.com/w/cpp/language/structured_binding
*/
#include <set>
#include <string>
#include <iomanip>
#include <iostream>
int main() {
    std::set<std::string> myset{"hello"};
    for (int i{2}; i; --i) {
        if (auto [iter, success] = myset.insert("Hello"); success) 
            std::cout << "Insert is successful. The value is " << std::quoted(*iter) << ".\n";
        else
            std::cout << "The value " << std::quoted(*iter) << " already exists in the set.\n";
    }
    struct BitFields {
        int b : 4 {1}, d : 4 {2}, p : 4 {3}, q : 4 {4};
        // C++20: default member initializer for bit-fields
    };
    {
        const auto [b, d, p, q] = BitFields{};
        std::cout << b << ' ' << d << ' ' << p << ' ' << q << '\n';
    }{
        const auto [b, d, p, q] = []{ return BitFields{4, 3, 2, 1}; }();
        std::cout << b << ' ' << d << ' ' << p << ' ' << q << '\n';
    }
}


/*
g++ -std=c++20 -o ../_build/r/gf.exe r/gf.cpp && (cd ../_build/r;./gf.exe)
*/

#include <concepts>
#include <iostream>

template <typename T>
struct Vector {
    Vector() {
        std::cout << "Vector<T>" << '\n';
    }
};

template <std::regular Reg>
struct Vector<Reg> {
    Vector() {
        std::cout << "Vector<std::regular>" << '\n';
    }
};

int main() {
    std::cout << '\n';
    Vector<int> myVec1;
    Vector<int&> myVec2;
    std::cout << '\n';
    }

/*
g++ -std=c++20 -o ../_build/r/gd.exe r/gd.cpp && (cd ../_build/r;./gd.exe)
*/

#include <concepts>
#include <compare>
#include <iostream>
#include <string>
#include <vector>

struct Test{};
void m1() {
    std::cout << '\n';
    std::cout << std::boolalpha;
    std::cout << "std::three_way_comparable<int>: " << std::three_way_comparable<int> << "\n";
    std::cout << "std::three_way_comparable<double>: ";
    if (std::three_way_comparable<double>) std::cout << "True";
    else std::cout << "False";
    std::cout << "\n\n";
    static_assert(std::three_way_comparable<std::string>);
    std::cout << "std::three_way_comparable<Test>: ";
    if constexpr(std::three_way_comparable<Test>) std::cout << "True";
    else std::cout << "False";
    std::cout << "\n\n";
    std::cout << "std::three_way_comparable<std::vector<int>>: ";
    if constexpr(std::three_way_comparable<std::vector<int>>) std::cout << "True";
    else std::cout << "False";
    std::cout << '\n';
}

template <std::regular T>
class My1Vector{};
void m2() {
    My1Vector<int> myVec1;
    // My1Vector<int&> myVec2; // ERROR because a reference is not regular
}

struct NotCopyable {
    NotCopyable() = default;
    NotCopyable(const NotCopyable&) = delete;
};
template <typename T>
struct My2Vector{
    void push_back(const T&) requires std::copyable<T> {}
};
void m3(){
    My2Vector<int> myVec1;
    myVec1.push_back(2020);
    My2Vector<NotCopyable> myVec2;
// myVec2.push_back(NotCopyable()); // ERROR because not copyable
}

template<std::integral... Args>
bool all(Args... args) { return (... && args); }
template<std::integral... Args>
bool any(Args... args) { return (... || args); }
template<std::integral... Args>
bool none(Args... args) { return not(... || args); }
void m4(){
    std::cout << std::boolalpha << '\n';
    std::cout << "all(5, true, false): " << all(5, true, false) << '\n';
    std::cout << "any(5, true, false): " << any(5, true, false) << '\n';
    std::cout << "none(5, true, false): " << none(5, true, false) << '\n';
}

int main(){
    m1();
    m2();
    m3();
    m4();
}

/*
g++ -std=c++20 -o ../_build/r/gj.exe r/gj.cpp && (cd ../_build/r;./gj.exe)
*/
#include <iostream>
#include <vector>

template <typename>
struct Other;
template <>
struct Other<std::vector<int>> {};
template<typename T>
concept TypeRequirement = requires {
    typename T::value_type;
    typename Other<T>;
};
void m1() {
    TypeRequirement auto myVec= std::vector<int>{1, 2, 3};
}
template<typename T>
concept Equal = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};
bool areEqual(Equal auto a, Equal auto b){
    return a == b;
}
struct WithoutEqual{
    bool operator==(const WithoutEqual& other) = delete;
};
struct WithoutUnequal{
    bool operator!=(const WithoutUnequal& other) = delete;
};
void m2() {
    std::cout << std::boolalpha << '\n';
    std::cout << "areEqual(1, 5): " << areEqual(1, 5) << '\n';
    /*
    bool res = areEqual(WithoutEqual(), WithoutEqual());
    bool res2 = areEqual(WithoutUnequal(), WithoutUnequal());
    */
    std::cout << '\n';
}
template <typename T>
concept Integral = std::is_integral<T>::value;
template <typename T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;
// template <typename T>
// concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;
template <typename T>
concept UnsignedIntegral = Integral<T> &&
requires(T) {
    requires !SignedIntegral<T>;
};
void m3() {
    UnsignedIntegral auto n = 5u; // works
    // UnsignedIntegral auto m = 5;
    // compile time error, 5 is a signed literal
}

int main(){
    m1();
    m2();
    m3();
}


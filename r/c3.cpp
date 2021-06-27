/*
g++ -std=c++20 -o ../_build/r/c3.exe r/c3.cpp && (cd ../_build/r;./c3.exe)
*/
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>
 
// the variant to visit
using var_t = std::variant<int, long, double, std::string>;
 
// helper constant for the visitor #3
template<class> inline constexpr bool always_false_v = false;
 
// helper type for the visitor #4
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
// // explicit deduction guide (not needed as of C++20)
// template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;
 
void manip(){
    std::cout.fill('#');
    std::cout << -12345;
    std::cout << std::setw(10) << -12345; // ####-12345
    std::cout << std::setw(10) << std::left << -12345; // -12345####
    std::cout << std::setw(10) << std::right << -12345; // ####-12345
    std::cout << std::setw(10) << std::internal << -12345; //-####12345
    std::cout << std::oct << 2011; // 3733
    std::cout << std::hex << 2011; // 7db
    std::cout << std::showbase;
    std::cout << std::dec << 2011; // 2011
    std::cout << std::oct << 2011; // 03733
    std::cout << std::hex << 2011; // 0x7db
    std::cout << 123.456789; // 123.457
    std::cout << std::fixed;
    std::cout << std::setprecision(3) << 123.456789; // 123.457
    std::cout << std::setprecision(6) << 123.456789; // 123.456789
    std::cout << std::setprecision(9) << 123.456789; // 123.456789000
    std::cout << std::scientific;
    std::cout << std::setprecision(3) << 123.456789; // 1.235e+02
    std::cout << std::setprecision(6) << 123.456789; // 1.234568e+02
    std::cout << std::setprecision(9) << 123.456789; // 1.234567890e+02
    std::cout << std::hexfloat;
    std::cout << std::setprecision(3) << 123.456789; // 0x1.edd3c07ee0b0bp+6
    std::cout << std::setprecision(6) << 123.456789; // 0x1.edd3c07ee0b0bp+6
    std::cout << std::setprecision(9) << 123.456789; // 0x1.edd3c07ee0b0bp+6
    std::cout << std::defaultfloat;
    std::cout << std::setprecision(3) << 123.456789; // 123
    std::cout << std::setprecision(6) << 123.456789; // 123.457
    std::cout << std::setprecision(9) << 123.456789; // 123.456789
}

int main() {
    std::vector<var_t> vec = {10, 15l, 1.5, "hello"};
    for(auto& v: vec) {
 
        // 1. void visitor, only called for side-effects (here, for I/O)
        std::visit([](auto&& arg){std::cout << arg;}, v);
 
        // 2. value-returning visitor, demonstrates the idiom of returning another variant
        var_t w = std::visit([](auto&& arg) -> var_t {return arg + arg;}, v);
 
        // 3. type-matching visitor: a lambda that handles each type differently
        std::cout << ". After doubling, variant holds ";
        std::visit([](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, int>)
                std::cout << "int with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, long>)
                std::cout << "long with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, double>)
                std::cout << "double with value " << arg << '\n';
            else if constexpr (std::is_same_v<T, std::string>)
                std::cout << "std::string with value " << std::quoted(arg) << '\n';
            else 
                static_assert(always_false_v<T>, "non-exhaustive visitor!");
        }, w);
    }
 
    for (auto& v: vec) {
        // 4. another type-matching visitor: a class with 3 overloaded operator()'s
        // Note: The `(auto arg)` template operator() will bind to `int` and `long`
        //       in this case, but in its absence the `(double arg)` operator()
        //       *will also* bind to `int` and `long` because both are implicitly
        //       convertible to double. When using this form, care has to be taken
        //       that implicit conversions are handled correctly.
        std::visit(overloaded {
            [](auto arg) { std::cout << arg << ' '; },
            [](double arg) { std::cout << std::fixed << arg << ' '; },
            [](const std::string& arg) { std::cout << std::quoted(arg) << ' '; },
        }, v);
    }

    manip();
}

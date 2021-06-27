/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_operator_cmp.exe ./cpp/utility_variant_operator_cmp.cpp && (cd ../_build/cpp/;./utility_variant_operator_cmp.exe)
https://en.cppreference.com/w/cpp/utility/variant/operator_cmp
*/
#include <iostream>
#include <string>
#include <variant>
int main()
{
    std::cout << std::boolalpha;
    std::string cmp;
    bool result;
    auto print2 = [&cmp, &result](const auto& lhs, const auto& rhs) {
        std::cout << lhs << ' ' << cmp << ' ' << rhs << " : " << result << '\n';
    };
    std::variant<int, std::string> v1, v2;
    std::cout << "operator==\n";
    {
        cmp = "==";
        // by default v1 = 0, v2 = 0;
        result = v1 == v2; // true
        std::visit(print2, v1, v2);
        v1 = v2 = 1;
        result = v1 == v2; // true
        std::visit(print2, v1, v2);
        v2 = 2;
        result = v1 == v2; // false
        std::visit(print2, v1, v2);
        v1 = "A";
        result = v1 == v2; // false: v1.index == 1, v2.index == 0
        std::visit(print2, v1, v2);
        v2 = "B";
        result = v1 == v2; // false
        std::visit(print2, v1, v2);
        v2 = "A";
        result = v1 == v2; // true
        std::visit(print2, v1, v2);
    }
    std::cout << "operator<\n";
    {
        cmp = "<";
        v1 = v2 = 1;
        result = v1 < v2; // false
        std::visit(print2, v1, v2);
        v2 = 2;
        result = v1 < v2; // true
        std::visit(print2, v1, v2);
        v1 = 3;
        result = v1 < v2; // false
        std::visit(print2, v1, v2);
        v1 = "A"; v2 = 1;
        result = v1 < v2; // false: v1.index == 1, v2.index == 0
        std::visit(print2, v1, v2);
        v1 = 1; v2 = "A";
        result = v1 < v2; // true: v1.index == 0, v2.index == 1
        std::visit(print2, v1, v2);
        v1 = v2 = "A";
        result = v1 < v2; // false
        std::visit(print2, v1, v2);
        v2 = "B";
        result = v1 < v2; // true
        std::visit(print2, v1, v2);
        v1 = "C";
        result = v1 < v2; // false
        std::visit(print2, v1, v2);
    }
    {
        std::variant<int, std::string> v1;
        std::variant<std::string, int> v2;
    //  v1 == v2;  // Compilation error: no known conversion
    }
    // TODO: C++20 three-way comparison operator <=> for variants
}


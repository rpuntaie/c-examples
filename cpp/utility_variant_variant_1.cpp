/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_variant_variant_1.exe ./cpp/utility_variant_variant_1.cpp && (cd ../_build/cpp/;./utility_variant_variant_1.exe)
https://en.cppreference.com/w/cpp/utility/variant/variant
*/
#include <cassert>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
template <class Os> Os& operator<< (Os& os, const std::vector<int>& v) {
    os << "{ ";
    for (int e: v) { std::cout << e << ' '; }
    return os << "}";
}
int main()
{
    {
        std::variant<int, std::string> var; // value-initializes first alternative
        assert(std::holds_alternative<int>(var) && var.index() == 0 &&
               std::get<int>(var) == 0);
    }
    {
        std::variant<std::string, int> var{"STR"};
            // initializes first alternative with std::string{"STR"};
        assert(var.index() == 0);
        std::cout << "1) " << std::get<std::string>(var) << '\n';
    }
    {
        std::variant<std::string, int> var{42};
            // initializes second alternative with int = 42;
        assert(std::holds_alternative<int>(var));
        std::cout << "2) " << std::get<int>(var) << '\n';
    }
    {
        std::variant<std::string, std::vector<int>, float> var{
            std::in_place_type<std::string>, 4, 'A'};
            // initializes first alternative with std::string{4, 'A'};
        assert(var.index() == 0);
        std::cout << "3) " << std::get<std::string>(var) << '\n';
    }
    {
        std::variant<std::string, std::vector<int>, char> var{
            std::in_place_type<std::vector<int>>, {1,2,3,4,5} };
            // initializes second alternative with std::vector{1,2,3,4,5};
        assert(var.index() == 1);
        std::cout << "4) " << std::get<std::vector<int>>(var) << '\n'; 
    }
    {
        std::variant<std::string, std::vector<int>, bool> var{
            std::in_place_index<0>, "ABCDE", 3};
            // initializes first alternative with std::string{"ABCDE", 3};
        assert(var.index() == 0);
        std::cout << "5) " << std::get<std::string>(var) << '\n';
    }
    {
        std::variant<std::string, std::vector<int>, char> var{
            std::in_place_index<1>, 4, 42};
            // initializes second alternative with std::vector(4, 42);
        assert(std::holds_alternative<std::vector<int>>(var));
        std::cout << "6) " << std::get<std::vector<int>>(var) << '\n';
    }
}


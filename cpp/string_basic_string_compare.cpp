/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_compare.exe ./cpp/string_basic_string_compare.cpp && (cd ../_build/cpp/;./string_basic_string_compare.exe)
https://en.cppreference.com/w/cpp/string/basic_string/compare
*/
#include <cassert>
#include <string>
#include <iostream>
int main() 
{
    // 1) Compare with other string
    {
        int compare_value{
            std::string{"Batman"}.compare(std::string{"Superman"})
        };
        std::cout << (
            compare_value < 0 ? "Batman comes before Superman\n" :
            compare_value > 0 ? "Superman comes before Batman\n" :
            "Superman and Batman are the same.\n"
        );
    }
    // 2) Compare substring with other string
    {
        int compare_value{
            std::string{"Batman"}.compare(3, 3, std::string{"Superman"})
        };
        std::cout << (
            compare_value < 0 ? "man comes before Superman\n" :
            compare_value > 0 ? "Superman comes before man\n" :
            "man and Superman are the same.\n"
        );
    }
    // 3) Compare substring with other substring
    {
        std::string a{"Batman"};
        std::string b{"Superman"};
        int compare_value{a.compare(3, 3, b, 5, 3)};
        std::cout << (
            compare_value < 0 ? "man comes before man\n" :
            compare_value > 0 ? "man comes before man\n" :
            "man and man are the same.\n"
        );
        // Compare substring with other substring
        // defaulting to end of other string
        assert(compare_value == a.compare(3, 3, b, 5));
    }
    // 4) Compare with char pointer
    {
        int compare_value{std::string{"Batman"}.compare("Superman")};
        std::cout << (
            compare_value < 0 ? "Batman comes before Superman\n" :
            compare_value > 0 ? "Superman comes before Batman\n" :
            "Superman and Batman are the same.\n"
        );
    }
    // 5) Compare substring with char pointer
    {
        int compare_value{std::string{"Batman"}.compare(3, 3, "Superman")};
        std::cout << (
            compare_value < 0 ? "man comes before Superman\n" :
            compare_value > 0 ? "Superman comes before man\n" :
            "man and Superman are the same.\n"
        );
    }
    // 6) Compare substring with char pointer substring
    {
        int compare_value{std::string{"Batman"}.compare(0, 3, "Superman", 5)};
        std::cout << (
            compare_value < 0 ? "Bat comes before Super\n" :
            compare_value > 0 ? "Super comes before Bat\n" :
            "Super and Bat are the same.\n"
        );
    }
}


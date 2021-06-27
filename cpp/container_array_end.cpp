/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_end.exe ./cpp/container_array_end.cpp && (cd ../_build/cpp/;./container_array_end.exe)
https://en.cppreference.com/w/cpp/container/array/end
*/
#include <array>
#include <iostream>
#include <algorithm>
#include <iomanip>
int main()
{
    std::cout << std::boolalpha;
    std::array<int, 0> empty;
    std::cout << "1) "
              << (empty.begin() == empty.end()) << ' '     // true
              << (empty.cbegin() == empty.cend()) << '\n'; // true
    // *(empty.begin()) = 42; // => undefined behaviour at run-time
    std::array<int, 4> numbers{5, 2, 3, 4};
    std::cout << "2) "
              << (numbers.begin() == numbers.end()) << ' '    // false
              << (numbers.cbegin() == numbers.cend()) << '\n' // false
              << "3) "
              << *(numbers.begin()) << ' '    // 5
              << *(numbers.cbegin()) << '\n'; // 5
    *numbers.begin() = 1;
    std::cout << "4) " << *(numbers.begin()) << '\n'; // 1
    // *(numbers.cbegin()) = 42; // compile-time error: 
                                 // read-only variable is not assignable
    // print out all elements
    std::cout << "5) ";
    std::for_each(numbers.cbegin(), numbers.cend(), [](int x) {
       std::cout << x << ' ';
    });
    std::cout << '\n';
    constexpr std::array constants{'A', 'B', 'C'};
    static_assert(constants.begin() != constants.end());   // OK
    static_assert(constants.cbegin() != constants.cend()); // OK
    static_assert(*constants.begin() == 'A');              // OK
    static_assert(*constants.cbegin() == 'A');             // OK
    // *constants.begin() = 'Z'; // compile-time error: 
                                 // read-only variable is not assignable
}


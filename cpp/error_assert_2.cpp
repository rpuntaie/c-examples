/*
g++ --std=c++20 -pthread -o ../_build/cpp/error_assert_2.exe ./cpp/error_assert_2.cpp && (cd ../_build/cpp/;./error_assert_2.exe) || true
https://en.cppreference.com/w/cpp/error/assert
*/
#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
int main()
{
    assert(2+2==4);
    std::cout << "Execution continues past the first assert\n";
    assertm(2+2==5, "There are five lights");
    std::cout << "Execution continues past the second assert\n";
    assert((2*2==4) && "Yet another way to add assert message");
}


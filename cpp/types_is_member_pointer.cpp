/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_member_pointer.exe ./cpp/types_is_member_pointer.cpp && (cd ../_build/cpp/;./types_is_member_pointer.exe)
https://en.cppreference.com/w/cpp/types/is_member_pointer
*/
#include <iostream>
#include <type_traits>
int main() {
    class cls {};
    std::cout << (std::is_member_pointer<int(cls::*)>::value
                     ? "T is member pointer"
                     : "T is not a member pointer") << '\n';
    std::cout << (std::is_member_pointer<int>::value
                     ? "T is member pointer"
                     : "T is not a member pointer") << '\n';
}


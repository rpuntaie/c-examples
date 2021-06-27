/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_remove_pointer.exe ./cpp/types_remove_pointer.cpp && (cd ../_build/cpp/;./types_remove_pointer.exe)
https://en.cppreference.com/w/cpp/types/remove_pointer
*/
#include <iostream>
#include <type_traits>
template<class T1, class T2>
void print_is_same() 
{
    std::cout << std::is_same<T1, T2>() << '\n';
}
void print_separator() 
{
    std::cout << "-----\n";
}
int main() 
{
    std::cout << std::boolalpha;
    print_is_same<int, int>();   // true
    print_is_same<int, int*>();  // false
    print_is_same<int, int**>(); // false
    print_separator();
    print_is_same<int, std::remove_pointer<int>::type>();   // true
    print_is_same<int, std::remove_pointer<int*>::type>();  // true
    print_is_same<int, std::remove_pointer<int**>::type>(); // false
    print_separator();
    print_is_same<int, std::remove_pointer<int* const>::type>();          // true
    print_is_same<int, std::remove_pointer<int* volatile>::type>();       // true
    print_is_same<int, std::remove_pointer<int* const volatile>::type>(); // true
}


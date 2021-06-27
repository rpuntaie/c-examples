/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_is_member_function_pointer.exe ./cpp/types_is_member_function_pointer.cpp && (cd ../_build/cpp/;./types_is_member_function_pointer.exe)
https://en.cppreference.com/w/cpp/types/is_member_function_pointer
*/
#include <type_traits>
class A {
public:
    void member() { }
};
int main()
{
    // fails at compile time if A::member is a data member and not a function
    static_assert(std::is_member_function_pointer<decltype(&A::member)>::value,
                  "A::member is not a member function."); 
}


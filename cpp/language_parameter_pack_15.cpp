/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_parameter_pack_15.exe ./cpp/language_parameter_pack_15.cpp && (cd ../_build/cpp/;./language_parameter_pack_15.exe)
https://en.cppreference.com/w/cpp/language/parameter_pack
*/
#include <iostream>
void tprintf(const char* format) // base function
{
    std::cout << format;
}
template<typename T, typename... Targs>
void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
{
    for ( ; *format != '\0'; format++ ) {
        if ( *format == '%' ) {
           std::cout << value;
           tprintf(format+1, Fargs...); // recursive call
           return;
        }
        std::cout << *format;
    }
}
int main()
{
    tprintf("% world% %\n","Hello",'!',123);
    return 0;
}


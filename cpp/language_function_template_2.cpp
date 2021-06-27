/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_function_template_2.exe ./cpp/language_function_template_2.cpp && (cd ../_build/cpp/;./language_function_template_2.exe)
https://en.cppreference.com/w/cpp/language/function_template
*/
#include <iostream>
template<typename T>
void f(T s)
{
    std::cout << s << '\n';
}
int main()
{
    f<double>(1); // instantiates and calls f<double>(double)
    f<>('a'); // instantiates and calls f<char>(char)
    f(7); // instantiates and calls f<int>(int)
    void (*ptr)(std::string) = f; // instantiates f<string>(string)
}


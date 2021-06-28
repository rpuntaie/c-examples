/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_user_literal.exe ./cpp/language_user_literal.cpp && (cd ../_build/cpp/;./language_user_literal.exe)
https://en.cppreference.com/w/cpp/language/user_literal
*/
#include <string>
long double operator "" _w(long double x){return x;};
std::string operator "" _w(const char16_t *x, size_t s)
{return std::string(reinterpret_cast<const char*>(x));}
unsigned operator "" _w(const char *x){return 0;};
int main() {
    1.2_w; // calls operator "" _w(1.2L)
    u"one"_w; // calls operator "" _w(u"one", 3)
    12_w; // calls operator "" _w("12")
    //"two"_w; // error: no applicable literal operator
}


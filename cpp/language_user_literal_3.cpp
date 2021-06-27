/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_user_literal_3.exe ./cpp/language_user_literal_3.cpp && (cd ../_build/cpp/;./language_user_literal_3.exe)
https://en.cppreference.com/w/cpp/language/user_literal
*/
#include <string>
void operator "" _km(long double); // OK, will be called for 1.0_km
std::string operator "" _i18n(const char*, std::size_t); // OK
template <char...> double operator "" _π(); // OK
float operator ""_e(const char*); // OK
float operator ""Z(const char*);   // error: suffix must begin with underscore
double operator"" _Z(long double); // error: all names that begin with underscore
                                   // followed by uppercase letter are reserved
double operator""_Z(long double);  // OK: even though _Z is reserved ""_Z is allowed
double operator ""_Z(const char* args); // OK: literal operators can be overloaded
int main() {}


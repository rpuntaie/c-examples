/*
# g++ --std=c++20 -pthread -o ../_build/cpp/keyword_reflexpr.exe ./cpp/keyword_reflexpr.cpp && (cd ../_build/cpp/;./keyword_reflexpr.exe)
https://en.cppreference.com/w/cpp/keyword/reflexpr
*/
#include <string>
#include <vector>
struct S {
    int b;
    std::string s;
    std::vector<std::string> v;
};
// Reflection TS
#include <experimental/reflect>
using meta_S = reflexpr(S);
using mem = std::reflect::get_data_members_t<meta_S>;
using meta = std::reflect::get_data_members_t<mem>;
static_assert(std::reflect::is_public_v<meta>); // successful
// P1240R1's meta library is easier
#include <experimantal/meta>
constexpr bool p = std::meta::is_public(reflexpr(S));
static_assert(p); // successful
int main() {}


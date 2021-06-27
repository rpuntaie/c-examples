/*
g++ --std=c++20 -pthread -o ../_build/cpp/keyword_reflexpr_1.exe ./cpp/keyword_reflexpr_1.cpp && (cd ../_build/cpp/;./keyword_reflexpr_1.exe)
https://en.cppreference.com/w/cpp/keyword/reflexpr
*/
#include <string>
#include <string_view>
#include <iostream>
// Reflection TS
#include <experimental/reflect>
template <typename Tp>
constexpr std::string_view nameof() {
 using TpInfo = reflexpr(Tp);
 using aliased_Info = std::experimental::reflect::get_aliased_t<TpInfo>;
 return std::experimental::reflect::get_name_v<aliased_Info>;
}
// P1240R1's meta library is easier!
#include <experimental/meta>
template<typename T>
constexpr std::string_view nameof() { 
 return std::meta::name_of(reflexpr(T));
}
int main(){
 std::cout << nameof<std::string>() << '\n';
 static_assert(nameof<std::string>() == "basic_string"); // successful
}


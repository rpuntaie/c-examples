/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_member_template.exe ./cpp/language_member_template.cpp && (cd ../_build/cpp/;./language_member_template.exe)
https://en.cppreference.com/w/cpp/language/member_template
*/
#include <iostream>
#include <vector>
#include <algorithm>
struct Printer { // generic functor
    std::ostream& os;
    Printer(std::ostream& os) : os(os) {}
    template<typename T>
    void operator()(const T& obj) { os << obj << ' '; } // member template
};
int main()
{
    std::vector<int> v = {1,2,3};
    std::for_each(v.begin(), v.end(), Printer(std::cout));
    std::string s = "abc";
    std::for_each(s.begin(), s.end(), Printer(std::cout));
}


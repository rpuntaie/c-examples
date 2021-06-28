/*
# g++ --std=c++23 -pthread -o ../_build/cpp/regex_basic_regex_deduction_guides.exe ./cpp/regex_basic_regex_deduction_guides.cpp && (cd ../_build/cpp/;./regex_basic_regex_deduction_guides.exe)
https://en.cppreference.com/w/cpp/regex/basic_regex/deduction_guides
*/
#include <regex>
#include <vector>
int main() {
   std::vector<char> v = {'a', 'b', 'c'};
   std::basic_regex re{v.begin(), v.end()}; // uses explicit deduction guide
}


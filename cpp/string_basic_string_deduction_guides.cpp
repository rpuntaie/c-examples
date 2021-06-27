/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_deduction_guides.exe ./cpp/string_basic_string_deduction_guides.cpp && (cd ../_build/cpp/;./string_basic_string_deduction_guides.exe)
https://en.cppreference.com/w/cpp/string/basic_string/deduction_guides
*/
#include <string>
#include <vector>
int main() {
   std::vector<char> v = {'a', 'b', 'c'};
   std::basic_string s(v.begin(), v.end()); // uses explicit deduction guide
}


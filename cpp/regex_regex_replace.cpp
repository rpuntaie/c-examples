/*
g++ --std=c++20 -pthread -o ../_build/cpp/regex_regex_replace.exe ./cpp/regex_regex_replace.cpp && (cd ../_build/cpp/;./regex_regex_replace.exe)
https://en.cppreference.com/w/cpp/regex/regex_replace
*/
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
int main()
{
   std::string text = "Quick brown fox";
   std::regex vowel_re("a|e|i|o|u");
   // write the results to an output iterator
   std::regex_replace(std::ostreambuf_iterator<char>(std::cout),
                      text.begin(), text.end(), vowel_re, "*");
   // construct a string holding the results
   std::cout << '\n' << std::regex_replace(text, vowel_re, "[$&]") << '\n';
}


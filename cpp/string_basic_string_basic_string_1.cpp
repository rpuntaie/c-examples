/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_basic_string_1.exe ./cpp/string_basic_string_basic_string_1.cpp && (cd ../_build/cpp/;./string_basic_string_basic_string_1.exe)
https://en.cppreference.com/w/cpp/string/basic_string/basic_string
*/
#include <iostream>
#include <iomanip>
#include <cassert>
#include <iterator>
#include <string>
#include <cctype>
int main()
{
  {
    std::cout << "1) string::string(); ";
    std::string s;
    assert(s.empty() && (s.length() == 0) && (s.size() == 0));
    std::cout << "s.capacity(): " << s.capacity() << '\n'; // unspecified
  }
  {
    std::cout << "2) string::string(size_type count, charT ch): ";
    std::string s(4, '=');
    std::cout << std::quoted(s) << '\n'; // "===="
  }
  {
    std::cout << "3) string::string(const string& other, "
                 "size_type pos, size_type count): ";
    std::string const other("Exemplary");
    std::string s(other, 0, other.length()-1);
    std::cout << quoted(s) << '\n'; // "Exemplar"
  }
  {
    std::cout << "4) string::string(const string& other, size_type pos): ";
    std::string const other("Mutatis Mutandis");
    std::string s(other, 8);
    std::cout << quoted(s) << '\n'; // "Mutandis", i.e. [8, 16)
  }
  {
    std::cout << "5) string::string(charT const* s, size_type count): ";
    std::string s("C-style string", 7);
    std::cout << quoted(s) << '\n'; // "C-style", i.e. [0, 7)
  }
  {
    std::cout << "6) string::string(charT const* s): ";
    std::string s("C-style\0string");
    std::cout << quoted(s) << '\n'; // "C-style"
  }
  {
    std::cout << "7) string::string(InputIt first, InputIt last): ";
    char mutable_c_str[] = "another C-style string";
    std::string s(std::begin(mutable_c_str)+8, std::end(mutable_c_str)-1);
    std::cout << quoted(s) << '\n'; // "C-style string"
  }
  {
    std::cout << "8) string::string(string&): ";
    std::string const other("Exemplar");
    std::string s(other);
    std::cout << quoted(s) << '\n'; // "Exemplar"
  }
  {
    std::cout << "9) string::string(string&&): ";
    std::string s(std::string("C++ by ") + std::string("example"));
    std::cout << quoted(s) << '\n'; // "C++ by example"
  }
  {
    std::cout << "α) string::string(std::initializer_list<charT>): ";
    std::string s({ 'C', '-', 's', 't', 'y', 'l', 'e' });
    std::cout << quoted(s) << '\n'; // "C-style"
  }
  {
    // overload resolution selects string(InputIt first, InputIt last)
    // [with InputIt = int] which behaves as if ...
    std::cout << "β) string::string(size_type count, charT ch) is called: ";
    std::string s(3, std::toupper('a'));
    std::cout << quoted(s) << '\n'; // "AAA"
  }
}


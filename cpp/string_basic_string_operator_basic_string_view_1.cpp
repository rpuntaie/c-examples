/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_operator_basic_string_view_1.exe ./cpp/string_basic_string_operator_basic_string_view_1.cpp && (cd ../_build/cpp/;./string_basic_string_operator_basic_string_view_1.exe)
https://en.cppreference.com/w/cpp/string/basic_string/operator_basic_string_view
*/
#include <iostream>
#include <string>
#include <string_view>
void show_wstring_size(std::wstring_view wcstr_v)
{
  std::cout << wcstr_v.size() << " code points\n";
}
int main()
{
  std::string cppstr = "ラーメン";   // narrow string
  std::wstring wcstr = L"ラーメン";  // wide string
  // Implicit conversion from string to string_view
  // via std::string::operator string_view:
  std::string_view cppstr_v = cppstr;
  std::cout << cppstr_v << '\n'
            << cppstr_v.size() << " code units\n";
  // Implicit conversion from wstring to wstring_view
  // via std::wstring::operator wstring_view:
  show_wstring_size(wcstr);
}


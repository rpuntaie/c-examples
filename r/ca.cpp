/*
g++ -std=c++20 -o ../_build/r/ca.exe r/ca.cpp && (cd ../_build/r;./ca.exe)
*/

#include <sstream>
#include <string>
#include <iostream>

template <typename T>
T StringTo ( const std::string& source ){
  std::istringstream iss(source);
  T ret;
  iss >> ret;
  return ret;
}
template <typename T>
std::string ToString(const T& n){
  std::ostringstream tmp ;
  tmp << n;
  return tmp.str();
}

int main()
{
  std::cout << "5= " << StringTo<int>("5"); // 5
  std::cout << "5 + 6= " << StringTo<int>("5") + 6; // 11
  std::cout << ToString(StringTo<int>("5") + 6 ); // "11"
  std::cout << "5e10: " << std::fixed << StringTo<double>("5e10"); // 50000000000
}


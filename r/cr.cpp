/*
g++ -std=c++20 -o ../_build/r/cr.exe r/cr.cpp && (cd ../_build/r;./cr.exe)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

int main()
{
  std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto newIt= std::remove_if(myVec.begin(), myVec.end(), [](int a){ return a%2; });
  for (auto v: myVec) std::cout << v << " "; // 0 2 4 6 8 5 6 7 8 9
  myVec.erase(newIt, myVec.end());
  for (auto v: myVec) std::cout << v << " "; // 0 2 4 6 8
  std::string s{"Only for Testing Purpose."};
  auto noUpper = std::remove_if(s.begin(), s.end(), [](char c){ return std::isupper(c); });
  s.erase(noUpper, s.end() );
  std::cout << s << std::endl; // nly for esting urpose.
}

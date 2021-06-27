/*
g++ -std=c++20 -o ../_build/r/cc.exe r/cc.cpp && (cd ../_build/r;./cc.exe)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>

int main()
{
  std::string maxLongLongString= std::to_string(std::numeric_limits<long long>::max());
  std::wstring maxLongLongWstring= std::to_wstring(std::numeric_limits<long long>::max());
  std::cout << std::numeric_limits<long long>::max(); // 9223372036854775807
  std::cout << maxLongLongString; // 9223372036854775807
  std::wcout << maxLongLongWstring; // 9223372036854775807
  std::string str("10010101");
  std::cout << std::stoi(str); // 10010101
  std::cout << std::stoi(str, nullptr, 16); // 268501249
  std::cout << std::stoi(str, nullptr, 8); // 2101313
  std::cout << std::stoi(str, nullptr, 2); // 149
  std::size_t idx;
  std::cout << std::stod(" 3.5 km", &idx); // 3.5
  std::cout << idx; // 6
  try{
    std::cout << std::stoi(" 3.5 km") << std::endl; // 3
    std::cout << std::stoi(" 3.5 km", nullptr, 2) << std::endl;
  }
  catch (const std::exception& e){
    std::cerr << e.what() << std::endl;
  } // stoi
/*
 std::numeric_limits<short>::max()
 std::numeric_limits<short>::max()
 std::numeric_limits<int>::max()
 std::numeric_limits<int>::max()
 std::numeric_limits<std::streamsize>::max()
 std::numeric_limits<std::streamsize>::max()
 std::numeric_limits<std::size_t>::max()
 std::numeric_limits<std::size_t>::max()
 std::numeric_limits<float>::max()
 std::numeric_limits<float>::max()
 std::numeric_limits<double>::max()
 std::numeric_limits<double>::max()
*/
}

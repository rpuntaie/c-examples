/*
g++ -std=c++20 -o ../_build/r/cv.exe r/cv.cpp && (cd ../_build/r;./cv.exe)
*/

#include <string_view>
#include <string>
#include <iostream>

void* operator new(std::size_t count){
  std::cout << " " << count << " bytes" << std::endl;
  return malloc(count);
}
void getString(const std::string&){}
void getStringView(std::string_view){}

int main()
{
  std::string large = "012345678901234567890"
                      "1234567890123456789"; // 41 bytes allocated
  std::string substr = large.substr(10); // 31 bytes allocated
  std::string_view largeStringView{large.c_str(), // 0 bytes allocated
  large.size()};
  largeStringView.remove_prefix(10); // 0 bytes allocated
  getString(large);
  getString("012345678901234567890"
  "1234567890123456789"); // 41 bytes allocated
  const char message []= "0123456789012345678901234567890123456789";
  getString(message); // 41 bytes allocated
  std::cout << "view: " << std::endl;
  getStringView(large); // 0 bytes allocated
  getStringView("012345678901234567890"
  "1234567890123456789"); // 0 bytes allocated
  getStringView(message); // 0 bytes allocated
}

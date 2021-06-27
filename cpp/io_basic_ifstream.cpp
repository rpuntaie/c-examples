/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_basic_ifstream.exe ./cpp/io_basic_ifstream.cpp && (cd ../_build/cpp/;./io_basic_ifstream.exe)
https://en.cppreference.com/w/cpp/io/basic_ifstream
*/
#include <iostream>
#include <fstream>
#include <string>
int main() {
  std::string filename = "Test.b";
  // prepare a file to read
  double d = 3.14;
  std::ofstream(filename, std::ios::binary).write(reinterpret_cast<char*>(&d), sizeof d)
     << 123 << "abc";
  // open file for reading
  std::ifstream istrm(filename, std::ios::binary);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << filename << '\n';
  } else {
    double d;
    istrm.read(reinterpret_cast<char*>(&d), sizeof d); // binary input
    int n;
    std::string s;
    if (istrm >> n >> s)                               // text input
      std::cout << "read back from file: " << d << ' ' << n << ' ' << s << '\n';
  }
}


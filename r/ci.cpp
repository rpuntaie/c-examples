/*
g++ -std=c++20 -o ../_build/r/ci.exe r/ci.cpp && (cd ../_build/r;./ci.exe)
*/

#include <iostream>
#include <string>
#include <fstream>

void writeFile(const std::string name){
  std::ofstream outFile(name);
  if (!outFile){
    std::cerr << "Could not open file " << name << std::endl;
    exit(1);
    }
  for (unsigned int i= 0; i < 10 ; ++i){
  outFile << i << " 0123456789" << std::endl;
  }
}

int main(){
  std::string random{"random.txt"};
  writeFile(random);
  std::ifstream inFile(random);
  if (!inFile){
    std::cerr << "Could not open file " << random << std::endl;
    exit(1);
    }
  std::string line;
  std::cout << inFile.rdbuf();
  // 0 0123456789
  // 1 0123456789
  //...
  // 9 0123456789
  std::cout << inFile.tellg() << std::endl; // 200
  inFile.seekg(0); // inFile.seekg(0, std::ios::beg);
  getline(inFile, line);
  std::cout << line; // 0 0123456789
  inFile.seekg(20, std::ios::cur);
  getline(inFile, line);
  std::cout << line; // 2 0123456789
  inFile.seekg(-20, std::ios::end);
  getline(inFile, line);
  std::cout << line; // 9 0123456789
}

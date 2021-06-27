/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_map_begin.exe ./cpp/container_map_begin.cpp && (cd ../_build/cpp/;./container_map_begin.exe)
https://en.cppreference.com/w/cpp/container/map/begin
*/
#include <iostream>
#include <map>
int main() {
  std::map<int, float> num_map;
  num_map[4] = 4.13;
  num_map[9] = 9.24;
  num_map[1] = 1.09;
  // calls a_map.begin() and a_map.end()
  for (auto it = num_map.begin(); it != num_map.end(); ++it) {
    std::cout << it->first << ", " << it->second << '\n';
  }
}


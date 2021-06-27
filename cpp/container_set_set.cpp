/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_set.exe ./cpp/container_set_set.cpp && (cd ../_build/cpp/;./container_set_set.exe)
https://en.cppreference.com/w/cpp/container/set/set
*/
#include <iostream>
#include <string>
#include <set>
#include <cmath>
struct Point { double x, y; };
struct PointCmp {
    bool operator()(const Point& lhs, const Point& rhs) const { 
        return std::hypot(lhs.x, lhs.y) < std::hypot(rhs.x, rhs.y); 
    }
};
int main()
{
  // (1) Default constructor
  std::set<std::string> a;
  a.insert("cat");
  a.insert("dog");
  a.insert("horse");
  for(auto& str: a) std::cout << str << ' ';
  std::cout << '\n';
  // (2) Iterator constructor
  std::set<std::string> b(a.find("dog"), a.end());
  for(auto& str: b) std::cout << str << ' ';
  std::cout << '\n';
  // (3) Copy constructor
  std::set<std::string> c(a);
  c.insert("another horse");
  for(auto& str: c) std::cout << str << ' ';
  std::cout << '\n';
  // (4) Move constructor
  std::set<std::string> d(std::move(a));
  for(auto& str: d) std::cout << str << ' ';
  std::cout << '\n';
  std::cout << "moved-from set is ";
  for(auto& str: a) std::cout << str << ' ';
  std::cout << '\n';
  // (5) Initializer list constructor
  std::set<std::string> e {"one", "two", "three", "five", "eight"};
  for(auto& str: e) std::cout << str << ' ';
  std::cout << '\n';
  // custom comparison
  std::set<Point, PointCmp> z = {{2, 5}, {3, 4}, {1, 1}};
  z.insert({1, -1}); // this fails because the magnitude of 1,-1 equals 1,1
  for(auto& p: z) std::cout << '(' << p.x << ',' << p.y << ") ";
  std::cout << '\n';
}


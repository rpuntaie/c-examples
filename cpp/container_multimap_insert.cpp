/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_multimap_insert.exe ./cpp/container_multimap_insert.cpp && (cd ../_build/cpp/;./container_multimap_insert.exe)
https://en.cppreference.com/w/cpp/container/multimap/insert
*/
#include <iostream>
#include <string>
#include <map>
#include <functional>
template<class M>
void print(const M& mmap)
{
    for (auto & e : mmap)
        std::cout << "{" << e.first << "," << e.second << "} ";
    std::cout << '\n';
}
int main()
{
  // list-initialize
  std::multimap<int, std::string, std::greater<int>> mmap 
    {{2, "foo"}, {2, "bar"}, {3, "baz"}, {1, "abc"}, {5, "def"}};
  // insert using value_type
  mmap.insert(decltype(mmap)::value_type(5, "pqr"));
  print(mmap);
  // insert using make_pair
  mmap.insert(std::make_pair(6, "uvw"));
  print(mmap);
  mmap.insert({7, "xyz"});
  print(mmap);
  // insert using initialization_list
  mmap.insert({{5, "one"}, {5, "two"}});
  print(mmap);
  // erase all entries with key 5
  mmap.erase(5);
  print(mmap);
  // find and erase a specific entry
  auto pos = mmap.begin();
  while (pos->second != "bar" && pos != mmap.end()) ++pos;
  mmap.erase(pos);
  print(mmap);
}


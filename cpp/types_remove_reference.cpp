/*
g++ --std=c++20 -pthread -o ../_build/cpp/types_remove_reference.exe ./cpp/types_remove_reference.cpp && (cd ../_build/cpp/;./types_remove_reference.exe)
https://en.cppreference.com/w/cpp/types/remove_reference
*/
#include <iostream> // std::cout
#include <type_traits> // std::is_same
template<class T1, class T2>
void print_is_same() {
  std::cout << std::is_same<T1, T2>() << '\n';
}
int main() {
  std::cout << std::boolalpha;
  print_is_same<int, int>();
  print_is_same<int, int &>();
  print_is_same<int, int &&>();
  print_is_same<int, std::remove_reference<int>::type>();
  print_is_same<int, std::remove_reference<int &>::type>();
  print_is_same<int, std::remove_reference<int &&>::type>();
}


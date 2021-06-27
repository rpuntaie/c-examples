/*
g++ -std=c++20 -o ../_build/r/c7.exe r/c7.cpp && (cd ../_build/r;./c7.exe)
*/
#include <iostream>
#include <type_traits>
int main()
{
  using std::cout;
  cout << std::is_void<void>::value; // true
  cout << std::is_integral<short>::value; // true
  cout << std::is_floating_point<double>::value; // true
  cout << std::is_array<int [] >::value; // true
  cout << std::is_pointer<int*>::value; // true
  cout << std::is_reference<int&>::value; // true
  struct A{
    int a;
    int f(int){ return 2011; }
  };
  cout << std::is_member_object_pointer<int A::*>::value; // true
  cout << std::is_member_function_pointer<int (A::*)(int)>::value; // true
  enum E{
    e= 1,
  };
  cout << std::is_enum<E>::value; // true
  union U{
    int u;
  };
  cout << std::is_union<U>::value; // true
  cout << std::is_class<std::string>::value; // true
  cout << std::is_function<int * (double)>::value; // true
  cout << std::is_lvalue_reference<int&>::value; // true
  cout << std::is_rvalue_reference<int&&>::value; // true
}

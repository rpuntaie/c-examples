/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_lambda_5.exe ./cpp/language_lambda_5.cpp && (cd ../_build/cpp/;./language_lambda_5.exe)
https://en.cppreference.com/w/cpp/language/lambda
*/
#include <iostream>
auto make_function(int& x) {
  return [&]{ std::cout << x << '\n'; };
}
int main() {
  int i = 3;
  auto f = make_function(i); // the use of x in f binds directly to i
  i = 5;
  f(); // OK; prints 5
}


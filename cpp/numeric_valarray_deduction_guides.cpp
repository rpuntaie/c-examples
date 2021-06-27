/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_valarray_deduction_guides.exe ./cpp/numeric_valarray_deduction_guides.cpp && (cd ../_build/cpp/;./numeric_valarray_deduction_guides.exe)
https://en.cppreference.com/w/cpp/numeric/valarray/deduction_guides
*/
#include <valarray>
int main() {
  int a[] = {1, 2, 3};
  std::valarray va(a, 3); // uses explicit deduction guide
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_comparison_4.exe ./cpp/language_operator_comparison_4.cpp && (cd ../_build/cpp/;./language_operator_comparison_4.exe)
https://en.cppreference.com/w/cpp/language/operator_comparison
*/
void f(char * p)
{
  if (p > 0) { /*...*/ } // Error with N3624, compiled before N3624
  if (p > nullptr) { /*...*/ } // Error with N3624, compiled before N3624
}
int main( ){ }


/*
gcc -std=c99 -pthread -o ../_build/c/language_attributes_fallthrough.exe ./c/language_attributes_fallthrough.c && (cd ../_build/c/;./language_attributes_fallthrough.exe)
https://en.cppreference.com/w/c/language/attributes/fallthrough
*/
#include <stdbool.h>
void g(void) {}
void h(void) {}
void i(void) {}
void f(int n) {
  switch (n) {
    case 1:
    case 2:
      g();
     [[fallthrough]];
    case 3: // no warning on fallthrough
      h();
    case 4: // compiler may warn on fallthrough
      if(n < 3) {
          i();
          [[fallthrough]]; // OK
      }
      else {
          return;
      }
    case 5:
      while (false) {
        [[fallthrough]]; // ill-formed: no subsequent case or default label
      }
    case 6:
      [[fallthrough]]; // ill-formed: no subsequent case or default label
  }
}
int main(void) {}


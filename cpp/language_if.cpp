/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_if.exe ./cpp/language_if.cpp && (cd ../_build/cpp/;./language_if.exe)
https://en.cppreference.com/w/cpp/language/if
*/
#include <iostream>
int main() {
    // simple if-statement with an else clause
    int i = 2;
    if (i > 2) {
        std::cout << i << " is greater than 2\n";
    } else {
        std::cout << i << " is not greater than 2\n";
    }
    // nested if-statement
    int j = 1;
    if (i > 1)
        if (j > 2)
            std::cout << i << " > 1 and " << j << " > 2\n";
        else // this else is part of if (j > 2), not of if (i > 1)
            std::cout << i << " > 1 and " << j << " <= 2\n";
   // declarations can be used as conditions with dynamic_cast
   struct Base {
        virtual ~Base() {}
   };
   struct Derived : Base {
       void df() { std::cout << "df()\n"; }
   };
   Base* bp1 = new Base;
   Base* bp2 = new Derived;
   if (Derived* p = dynamic_cast<Derived*>(bp1)) // cast fails, returns nullptr
       p->df();  // not executed
   if (auto p = dynamic_cast<Derived*>(bp2)) // cast succeeds
       p->df();  // executed
}


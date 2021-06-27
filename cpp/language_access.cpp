/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_access.exe ./cpp/language_access.cpp && (cd ../_build/cpp/;./language_access.exe)
https://en.cppreference.com/w/cpp/language/access
*/
#include <iostream>
class Example {
  public:             // all declarations after this point are public
    void add(int x) { // member "add" has public access
      n += x;         // OK: private Example::n can be accessed from Example::add
    }
  private:            // all declarations after this point are private
    int n = 0;        // member "n" has private access
};
int main() {
  Example e;
  e.add(1); // OK: public Example::add can be accessed from main
//e.n = 7;  // error: private Example::n cannot be accessed from main
}


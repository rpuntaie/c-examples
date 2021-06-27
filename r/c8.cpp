/*
g++ -std=c++20 -o ../_build/r/c8.exe r/c8.cpp && (cd ../_build/r;./c8.exe)
*/
#include <exception>
#include <iostream>
using namespace std;

class MyBase { public: 
  //attributes
  [[deprecated("noexept is not needed here")]]
  constexpr virtual int test() noexcept {return 3;}
};
class MyChild : public MyBase {};

consteval int doubleIt(int i) {
 return 2*i;
}

int main()
{
 MyBase *base = new MyBase();
 try {
   MyChild &child = dynamic_cast<MyChild&>(*base);
 }
 catch(const bad_cast &e) {
   cout << e.what();
   //throw;
   }
 delete base;
 constexpr int a = doubleIt(MyBase().test()); // ok
 cout << endl << a;
 union { short s; }; // defines an unnamed union object
 s = 15;
 cout << endl << s;
}

// static_cast<new_type> (expression)
// reinterpret_cast<new_type> (expression)
// const_cast<new_type> (expression)
// dynamic_cast<new_type> (expression)

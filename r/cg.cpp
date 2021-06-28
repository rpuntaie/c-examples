/*
g++ -std=c++20 -o ../_build/r/cg.exe r/cg.cpp && (cd ../_build/r;./cg.exe)
*/
#include <iostream>

using namespace std;
enum class Color { red, green, blue };
void colorPrint(Color c)
{
 // Import enum members to local scope
 using enum Color;
 switch (c)
 {
 case red: cout << "red" << endl; break;
 case green: cout << "green" << endl; break;
 case blue: cout << "blue" << endl; break;
 }
}

class B2
{
 public:
 int x;
 B2(int a) : x(a) {}
};
class D2 : public B2
{
 public:
 using B2::B2; // inherit all constructors from B2
 int y { 0 };
};

class TestClass
{
 public:
 int a = 1;
 int b = 2;
};
void iit()
{
 TestClass o1 { .a = 3, .b = 4 }; // ok, a = 3, b = 4
 TestClass o2 { .a = 5 }; // ok, a = 5, b = 2
 TestClass o3 { .b = 6 }; // ok, a = 1, b = 6
}

class A
{
 public:
 // Explicitly include default constructor
 A() = default;
 // Explicitly include default destructor
 ~A() = default;
 // Disable move constructor
 A(A&&) noexcept = delete;
 // Disable move assignment operator
 A& operator=(A&&) noexcept = delete;
 // Disable copy constructor
 A(const A&) = delete;
 // Disable copy assignment operator
 A& operator=(const A&) = delete;
};

int main()
{
  colorPrint(Color::red);
  colorPrint(Color::green);


  D2 d(3); // call inherited B2 constructor
  cout << d.x; // "3"

  iit();

  A();

//  string f = std::format("{1} is more than {0}", "zero", 5);
//  cout << f;
}

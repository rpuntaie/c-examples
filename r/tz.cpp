/*
clang -std=c++20 -lstdc++ -o ../_build/r/tz.exe r/tz.cpp && (cd ../_build/r;./tz.exe)
*/

struct B1 {  B1(int, ...) { } };
struct B2 {  B2(double)   { } };
int get(){return 1;}
struct D1 : B1 {
  using B1::B1;  // inherits B1(int, ...)
  int x;
  int y = get();
};
void test() {
  D1 d(2, 3, 4); // OK: B1 is initialized by calling B1(2, 3, 4),
                 // then d.x is default-initialized (no initialization is performed),
                 // then d.y is initialized by calling get()
  //D1 e;          // Error: D1 has no default constructor
}
struct D2 : B2 {
  using B2::B2; // inherits B2(double)
  B1 b;
};
//D2 f(1.0);       // error: B1 has no default constructor

int main()
{
    test();
}


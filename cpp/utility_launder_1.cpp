/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_launder_1.exe ./cpp/utility_launder_1.cpp && (cd ../_build/cpp/;./utility_launder_1.exe)
https://en.cppreference.com/w/cpp/utility/launder
*/
#include <new>
#include <cstddef>
#include <cassert>
struct X {
  const int n; // note: X has a const member
  int m;
};
struct Y {
  int z;
};
struct A { 
    virtual int transmogrify();
};
struct B : A {
    int transmogrify() override { new(this) A; return 2; }
};
int A::transmogrify() { new(this) B; return 1; }
static_assert(sizeof(B) == sizeof(A));
int main()
{
  // Case 1: the new object failed to be transparently replaceable because of
  // a subobject of const-qualified or reference type.
  // Note: this case is a defect fixed via RU007 (included in P1971R0),
  // so std::launder is no longer needed in this case since RU007.
  X *p = new X{3, 4};
  const int a = p->n;
  X* np = new (p) X{5, 6}; // p does not point to new object because X::n is const
  // until RU007; np points to the new object; so does p since RU007
  const int b = p->n; // undefined behavior until RU007; OK since RU007
  const int c = p->m; // undefined behavior until RU007:
  // even though m is non-const, p can't be used; OK since RU007
  const int d = std::launder(p)->n; // OK: std::launder(p) points to new object
  const int e = np->n; // OK
  // Case 2: the new object failed to be transparently replaceable because it is a
  // base subobject but the old object is a complete object.
  A i;
  int n = i.transmogrify();
  // int m = i.transmogrify(); // undefined behavior
  int m = std::launder(&i)->transmogrify(); // OK
  assert(m + n == 3);
  // Case 3: access to a new object whose storage is provided by a byte array through
  // a pointer to the array.
  alignas(Y) std::byte s[sizeof(Y)];
  Y* q = new(&s) Y{2};
  const int f = reinterpret_cast<Y*>(&s)->z; // Class member access is undefined behavior:
                                             // reinterpret_cast<Y*>(&s) has value
                                             // "pointer to s" and does not
                                             // point to a Y object 
  const int g = q->z; // OK
  const int h = std::launder(reinterpret_cast<Y*>(&s))->z; // OK
  [](auto...){}(a, b, d, c, e, f, g, h);  // suppress "unused-variable" warnings
}


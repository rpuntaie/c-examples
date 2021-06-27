/*
gcc -std=c99 -pthread -o ../_build/c/language_return.exe ./c/language_return.c && (cd ../_build/c/;./language_return.exe)
https://en.cppreference.com/w/c/language/return
*/
struct s { double i; } f(void); // function returning struct s
union { struct { int f1; struct s f2; } u1;
        struct { struct s f3; int f4; } u2; } g;
struct s f(void)
{
    return g.u1.f2;
}
int main(void)
{
// g.u2.f3 = g.u1.f2; // undefined behavior (overlap in assignment)
   g.u2.f3 = f();     // well-defined
}


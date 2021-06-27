/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_13.exe ./cpp/language_pointer_13.cpp && (cd ../_build/cpp/;./language_pointer_13.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
struct Base { int m; };
struct Derived : Base {};
int main()
{
    int Base::* bp = &Base::m;
    int Derived::* dp = bp;
    Derived d;
    d.m = 1;
    std::cout << d.*dp << ' ' << d.*bp << '\n'; // prints 1 1
}


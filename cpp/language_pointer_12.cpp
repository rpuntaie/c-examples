/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_12.exe ./cpp/language_pointer_12.cpp && (cd ../_build/cpp/;./language_pointer_12.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
struct C { int m; };
int main()
{
    int C::* p = &C::m;          // pointer to data member m of class C
    C c = {7};
    std::cout << c.*p << '\n';   // prints 7
    C* cp = &c;
    cp->m = 10;
    std::cout << cp->*p << '\n'; // prints 10
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_union_3.exe ./cpp/language_union_3.cpp && (cd ../_build/cpp/;./language_union_3.exe)
https://en.cppreference.com/w/cpp/language/union
*/
#include <iostream>
// S has one non-static data member (tag), three enumerator members (CHAR, INT, DOUBLE), 
// and three variant members (c, i, d)
struct S
{
    enum{CHAR, INT, DOUBLE} tag;
    union
    {
        char c;
        int i;
        double d;
    };
};
void print_s(const S& s)
{
    switch(s.tag)
    {
        case S::CHAR: std::cout << s.c << '\n'; break;
        case S::INT: std::cout << s.i << '\n'; break;
        case S::DOUBLE: std::cout << s.d << '\n'; break;
    }
}
int main()
{
    S s = {S::CHAR, 'a'};
    print_s(s);
    s.tag = S::INT;
    s.i = 123;
    print_s(s);
}


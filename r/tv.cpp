/*
g++ -std=c++20 -o ../_build/r/tv.o -c r/tv.cpp
*/

#include<memory>
#include<string>

struct S{
    int i;
    bool b;
};
void f(){
    void* p;
    //S s{1, p};          // error
    //bool b1{p};         // error
    bool b2 = p;        // OK
    bool b3{nullptr};   // OK
    //bool b4 = nullptr;  // error
    //bool b5 = {nullptr};// error
    if(p){/*...*/}      // OK
}

void xy(){
volatile int x{};
x++;            // deprecated
int y = x = 1;  // deprecated
x = 1;          // OK
y = x;          // OK
x += 2;         // deprecated
}
volatile int            //deprecated
    ff(volatile int);    //deprecated


struct SPath{
    SPath(int);
    SPath operator,(const SPath&);  // store path somehow
};
struct S1{
    int operator[](SPath); // use path
};
void xx(){
S1 s1;
auto x1 = s1[1,2,3];    // deprecated
auto x2 = s1[(1,2,3)];  // OK
}
// // future approach
// struct S2{
//     int operator[](int, int, int);
//     // or, as a variadic template
//     template<typename... IndexType>
//     int operator[](IndexType...);
// };
// void yy(){
// S2 s2;
// auto x3 = s2[1,2,3];
// }

/*
g++ -std=c++20 -fmodules-ts r/tmm.internals.cpp r/tmm.helpers.cpp r/tmm.impl.cpp r/tmm.impl2.cpp r/tmm.cpp r/tmmc.cpp
*/

import tmm;

int main(){
f();
h();
g();
//// error, if not exported
//g();
//
//
B b;
b.f();  // OK
b.g();  // error, A is undefined (no error with g++ 11.1.0)
b.h();  // OK
return 0;
}



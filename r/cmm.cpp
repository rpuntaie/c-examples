/*
g++ -std=c++20 -fmodules-ts -o ../_build/r/cmm.o -c r/cmm.cpp
*/
module;
export module cmm;
#define VALUE 5
int hidden() { return VALUE; }
export int getValue() { return hidden(); }

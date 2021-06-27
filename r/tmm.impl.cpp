/*
g++ -std=c++20 -fmodules-ts -c r/tmm.impl.cpp
*/

module tmm;    // implementation unit, implicitly imports primary module unit
import :internals;

void utility(){}

void f(){
    utility();
}

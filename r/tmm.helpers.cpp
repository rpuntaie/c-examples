/*
g++ -std=c++20 -fmodules-ts -o ../_build/r/tmm.helpers.o -c r/tmm.helpers.cpp
*/

export module tmm:helpers; // module interface partition
import :internals;

export void h(){
    utility();
}

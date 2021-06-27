/*
g++ -std=c++20 -fmodules-ts -o ../_build/r/cm.exe r/cmm.cpp r/cm.cpp && (cd ../_build/r;./cm.exe)
*/
import cmm;
#include <iostream>
using namespace std;
int main()
{ cout << getValue() << endl; }

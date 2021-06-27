/*
g++ -std=c++20 -o ../_build/r/cn.exe r/cn.cpp && (cd ../_build/r;./cn.exe)
*/
#include <stdio.h>
using namespace std;
namespace a{
    void p(){printf("p");}
}
namespace b{
    using a::p;
    void pp(){p();}
}
int main()
{
    b::pp();
}


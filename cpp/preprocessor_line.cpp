/*
g++ --std=c++20 -pthread -o ../_build/cpp/preprocessor_line.exe ./cpp/preprocessor_line.cpp && (cd ../_build/cpp/;./preprocessor_line.exe) || true
https://en.cppreference.com/w/cpp/preprocessor/line
*/
#include <cassert>
#define FNAME "test.cc"
int main()
{
#line 777 FNAME
        assert(2+2 == 5);
}


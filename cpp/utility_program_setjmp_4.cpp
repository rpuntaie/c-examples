/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_setjmp_4.exe ./cpp/utility_program_setjmp_4.cpp && (cd ../_build/cpp/;./utility_program_setjmp_4.exe)
https://en.cppreference.com/w/cpp/utility/program/setjmp
*/
#include <iostream>
#include <csetjmp>
std::jmp_buf jump_buffer;
[[noreturn]] void a(int count) 
{
    std::cout << "a(" << count << ") called\n";
    std::longjmp(jump_buffer, count+1);  // setjmp() will return count+1
}
int main()
{
    volatile int count = 0; // modified locals in setjmp scope must be volatile
    if (setjmp(jump_buffer) != 9) { // equality against constant expression in an if
        a(++count);  // This will cause setjmp() to exit
    }
}


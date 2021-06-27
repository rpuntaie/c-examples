/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_program_longjmp.exe ./cpp/utility_program_longjmp.cpp && (cd ../_build/cpp/;./utility_program_longjmp.exe)
https://en.cppreference.com/w/cpp/utility/program/longjmp
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
    volatile int count = 0; // local variables must be volatile for setjmp
    if (setjmp(jump_buffer) != 9) {
        a(count++);  // This will cause setjmp() to exit
    }
}


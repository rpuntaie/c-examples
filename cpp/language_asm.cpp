/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_asm.exe ./cpp/language_asm.cpp && (cd ../_build/cpp/;./language_asm.exe) || true
https://en.cppreference.com/w/cpp/language/asm
*/
#include <iostream>
extern "C" int func();
// the definition of func is written in assembly language
// raw string literal could be very useful
asm(R"(
.globl func
    .type func, @function
    func:
    .cfi_startproc
    movl $7, %eax
    ret
    .cfi_endproc
)");
int main()
{
    int n = func();
    // extended inline assembly
    asm ("leal (%0,%0,4),%0"
         : "=r" (n)
         : "0" (n));
    std::cout << "7*5 = " << n << std::endl; // flush is intentional
    // standard inline assembly
    asm ("movq $60, %rax\n\t" // the exit syscall number on Linux
         "movq $2,  %rdi\n\t" // this program returns 2
         "syscall");
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_setvbuf.exe ./cpp/io_c_setvbuf.cpp && (cd ../_build/cpp/;./io_c_setvbuf.exe)
https://en.cppreference.com/w/cpp/io/c/setvbuf
*/
#include <cstdio>
int main() {
    char buf[BUFSIZ];
    std::setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior


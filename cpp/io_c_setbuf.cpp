/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_setbuf.exe ./cpp/io_c_setbuf.cpp && (cd ../_build/cpp/;./io_c_setbuf.exe)
https://en.cppreference.com/w/cpp/io/c/setbuf
*/
#include <cstdio>
int main() {
    char buf[BUFSIZ];
    std::setbuf(stdin, buf);
} // lifetime of buf ends, undefined behavior


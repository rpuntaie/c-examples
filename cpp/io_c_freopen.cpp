/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_freopen.exe ./cpp/io_c_freopen.cpp && (cd ../_build/cpp/;./io_c_freopen.exe)
https://en.cppreference.com/w/cpp/io/c/freopen
*/
#include <cstdio>
int main()
{
    std::printf("stdout is printed to console\n");
    if(std::freopen("redir.txt", "w", stdout)) {
        std::printf("stdout is redirected to a file\n"); // this is written to redir.txt
        std::fclose(stdout);
    }
}


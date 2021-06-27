/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_tmpfile.exe ./cpp/io_c_tmpfile.cpp && (cd ../_build/cpp/;./io_c_tmpfile.exe)
https://en.cppreference.com/w/cpp/io/c/tmpfile
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    std::cout << "TMP_MAX = " << TMP_MAX << '\n'
              << "FOPEN_MAX = " << FOPEN_MAX << '\n';
    std::FILE* tmpf = std::tmpfile();
    std::fputs("Hello, world", tmpf);
    std::rewind(tmpf);
    char buf[6];
    std::fgets(buf, sizeof buf, tmpf);
    std::cout << buf << '\n';
    // Linux-specific method to display the tmpfile name
    std::cout << fs::read_symlink(
                     fs::path("/proc/self/fd") / std::to_string(fileno(tmpf))
                 ) << '\n';
}


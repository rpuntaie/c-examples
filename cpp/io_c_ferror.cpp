/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_ferror.exe ./cpp/io_c_ferror.cpp && (cd ../_build/cpp/;./io_c_ferror.exe)
https://en.cppreference.com/w/cpp/io/c/ferror
*/
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cwchar>
int main(void)
{
    const char *fname = std::tmpnam(nullptr);
    std::FILE* f = std::fopen(fname, "wb");
    std::fputs("\xff\xff\n", f); // not a valid UTF-8 character sequence
    std::fclose(f);
    std::setlocale(LC_ALL, "en_US.utf8");
    f = std::fopen(fname, "rb");
    std::wint_t ch;
    while ((ch=std::fgetwc(f)) != WEOF) // attempt to read as UTF-8
          std::printf("%#x ", ch);
    if (std::feof(f))
        puts("EOF indicator set");
    if (std::ferror(f))
        puts("Error indicator set");
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_c_setvbuf_1.exe ./cpp/io_c_setvbuf_1.cpp && (cd ../_build/cpp/;./io_c_setvbuf_1.exe) || true
https://en.cppreference.com/w/cpp/io/c/setvbuf
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/stat.h>
int main()
{
    std::FILE* fp = std::fopen("/tmp/test.txt", "w+");
    if(!fp) {
       std::perror("fopen"); return EXIT_FAILURE;
    }
    struct stat stats;
    if(fstat(fileno(fp), &stats) == -1) { // POSIX only
        std::perror("fstat"); return EXIT_FAILURE;
    }
    std::cout << "BUFSIZ is " << BUFSIZ << ", but optimal block size is "
              << stats.st_blksize << '\n';
    if(std::setvbuf(fp, nullptr, _IOFBF, stats.st_blksize) != 0) {
       std::perror("setvbuf failed"); // POSIX version sets errno
       return EXIT_FAILURE;
    }
    // read entire file: use truss/strace
    // to observe the read(2) syscalls used
    for (int ch; (ch = std::fgetc(fp)) != EOF; ) {}
    std::fclose(fp);
    return EXIT_SUCCESS;
}


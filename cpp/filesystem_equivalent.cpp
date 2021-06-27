/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_equivalent.exe ./cpp/filesystem_equivalent.cpp && (cd ../_build/cpp/;./filesystem_equivalent.exe)
https://en.cppreference.com/w/cpp/filesystem/equivalent
*/
#include <iostream>
#include <cstdint>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    // hard link equivalency
    fs::path p1 = ".";
    fs::path p2 = fs::current_path();
    if(fs::equivalent(p1, p2))
        std::cout << p1 << " is equivalent to " << p2 << '\n';
    // symlink equivalency
    for(const fs::path lib : {"/lib/libc.so.6", "/lib/x86_64-linux-gnu/libc.so.6"}) {
        try {
          p2 = lib.parent_path() / fs::read_symlink(lib);
        } catch(std::filesystem::filesystem_error const& ex) {
            std::cout << ex.what() << '\n';
            continue;
        }
        if(fs::equivalent(lib, p2))
            std::cout << lib << " is equivalent to " << p2 << '\n';
    }
}


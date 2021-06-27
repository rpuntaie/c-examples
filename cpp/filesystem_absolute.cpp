/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_absolute.exe ./cpp/filesystem_absolute.cpp && (cd ../_build/cpp/;./filesystem_absolute.exe)
https://en.cppreference.com/w/cpp/filesystem/absolute
*/
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    std::filesystem::path p = "foo.c";
    std::cout << "Current path is " << fs::current_path() << '\n';
    std::cout << "Absolute path for " << p << " is " 
              << std::filesystem::absolute(p) << '\n';
}


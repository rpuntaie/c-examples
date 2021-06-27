/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_create_hard_link.exe ./cpp/filesystem_create_hard_link.cpp && (cd ../_build/cpp/;./filesystem_create_hard_link.exe)
https://en.cppreference.com/w/cpp/filesystem/create_hard_link
*/
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    fs::create_directories("sandbox/subdir");
    std::ofstream("sandbox/a").put('a'); // create regular file
    fs::create_hard_link("sandbox/a", "sandbox/b");
    fs::remove("sandbox/a");
    // read from the original file via surviving hard link
    char c = std::ifstream("sandbox/b").get();
    std::cout << c << '\n';
    fs::remove_all("sandbox");
}


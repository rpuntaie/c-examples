/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_remove.exe ./cpp/filesystem_remove.cpp && (cd ../_build/cpp/;./filesystem_remove.exe)
https://en.cppreference.com/w/cpp/filesystem/remove
*/
#include <iostream>
#include <cstdint>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    fs::path tmp = fs::temp_directory_path();
    fs::create_directories(tmp / "abcdef/example");
    std::uintmax_t n = fs::remove_all(tmp / "abcdef");
    std::cout << "Deleted " << n << " files or directories\n";
}


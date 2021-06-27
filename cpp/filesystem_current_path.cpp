/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_current_path.exe ./cpp/filesystem_current_path.cpp && (cd ../_build/cpp/;./filesystem_current_path.exe)
https://en.cppreference.com/w/cpp/filesystem/current_path
*/
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    std::cout << "Current path is " << fs::current_path() << '\n'; // (1)
    fs::current_path(fs::temp_directory_path()); // (3)
    std::cout << "Current path is " << fs::current_path() << '\n';
}


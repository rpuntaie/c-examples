/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_temp_directory_path.exe ./cpp/filesystem_temp_directory_path.cpp && (cd ../_build/cpp/;./filesystem_temp_directory_path.exe)
https://en.cppreference.com/w/cpp/filesystem/temp_directory_path
*/
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    std::cout << "Temp directory is " << fs::temp_directory_path() << '\n';
}


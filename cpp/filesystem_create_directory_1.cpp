/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_create_directory_1.exe ./cpp/filesystem_create_directory_1.cpp && (cd ../_build/cpp/;./filesystem_create_directory_1.exe)
https://en.cppreference.com/w/cpp/filesystem/create_directory
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    fs::current_path(fs::temp_directory_path());
    fs::create_directories("sandbox/1/2/a");
    fs::create_directory("sandbox/1/2/b");
    fs::permissions("sandbox/1/2/b", fs::perms::others_all, fs::perm_options::remove);
    fs::create_directory("sandbox/1/2/c", "sandbox/1/2/b");
    std::system("ls -l sandbox/1/2");
    std::system("tree sandbox");
    fs::remove_all("sandbox");
}


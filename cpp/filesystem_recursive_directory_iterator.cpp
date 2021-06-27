/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_recursive_directory_iterator.exe ./cpp/filesystem_recursive_directory_iterator.cpp && (cd ../_build/cpp/;./filesystem_recursive_directory_iterator.exe)
https://en.cppreference.com/w/cpp/filesystem/recursive_directory_iterator
*/
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    fs::current_path(fs::temp_directory_path());
    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    fs::create_symlink("a", "sandbox/syma");
    for(auto& p: fs::recursive_directory_iterator("sandbox"))
        std::cout << p.path() << '\n';
    fs::remove_all("sandbox");
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_directory_iterator.exe ./cpp/filesystem_directory_iterator.cpp && (cd ../_build/cpp/;./filesystem_directory_iterator.exe)
https://en.cppreference.com/w/cpp/filesystem/directory_iterator
*/
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    for(auto& p: fs::directory_iterator("sandbox"))
        std::cout << p.path() << '\n';
    fs::remove_all("sandbox");
}


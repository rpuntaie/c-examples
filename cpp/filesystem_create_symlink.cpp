/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_create_symlink.exe ./cpp/filesystem_create_symlink.cpp && (cd ../_build/cpp/;./filesystem_create_symlink.exe)
https://en.cppreference.com/w/cpp/filesystem/create_symlink
*/
#include <iostream>
#include <filesystem>
#include <cassert>
namespace fs = std::filesystem;
int main()
{
    fs::create_directories("sandbox/subdir");
    fs::create_symlink("target", "sandbox/sym1");
    fs::create_directory_symlink("subdir", "sandbox/sym2");
    for(auto it = fs::directory_iterator("sandbox"); it != fs::directory_iterator(); ++it)
        if(is_symlink(it->symlink_status()))
            std::cout << *it << "->" << read_symlink(*it) << '\n';
    assert( std::filesystem::equivalent("sandbox/sym2", "sandbox/subdir") );
    fs::remove_all("sandbox");
}


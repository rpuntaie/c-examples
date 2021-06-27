/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_exists.exe ./cpp/filesystem_exists.cpp && (cd ../_build/cpp/;./filesystem_exists.exe)
https://en.cppreference.com/w/cpp/filesystem/exists
*/
#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
namespace fs = std::filesystem;
void demo_exists(const fs::path& p, fs::file_status s = fs::file_status{})
{
    std::cout << p;
    if(fs::status_known(s) ? fs::exists(s) : fs::exists(p))
        std::cout << " exists\n";
    else
        std::cout << " does not exist\n";
}
int main()
{
    fs::create_directory("sandbox");
    std::ofstream("sandbox/file"); // create regular file
    fs::create_symlink("non-existing", "sandbox/symlink");
    demo_exists("sandbox");
    for(auto it = fs::directory_iterator("sandbox"); it != fs::directory_iterator(); ++it)
        demo_exists(*it, it->status()); // use cached status from directory entry
    fs::remove_all("sandbox");
}


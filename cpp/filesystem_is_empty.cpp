/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_is_empty.exe ./cpp/filesystem_is_empty.cpp && (cd ../_build/cpp/;./filesystem_is_empty.exe)
https://en.cppreference.com/w/cpp/filesystem/is_empty
*/
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstdio>
int main()
{
    namespace fs = std::filesystem;
    const fs::path tmp_dir{ fs::temp_directory_path() };
    std::cout << std::boolalpha
              << "Temp dir: " << tmp_dir << '\n'
              << "is_empty(): " << fs::is_empty(tmp_dir) << '\n';
    const fs::path tmp_name{ tmp_dir / std::tmpnam(nullptr) };
    std::cout << "Temp file: " << tmp_name << '\n';
    std::ofstream file{ tmp_name.string() };
    std::cout << "is_empty(): " << fs::is_empty(tmp_name) << '\n';
    file << "cppreference.com";
    file.flush();
    std::cout << "is_empty(): " << fs::is_empty(tmp_name) << '\n'
              << "file_size(): " << fs::file_size(tmp_name) << '\n';
    file.close();
    fs::remove(tmp_name);
}


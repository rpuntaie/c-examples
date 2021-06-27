/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_relative.exe ./cpp/filesystem_relative.cpp && (cd ../_build/cpp/;./filesystem_relative.exe)
https://en.cppreference.com/w/cpp/filesystem/relative
*/
#include <iostream>
#include <filesystem>
void show(std::filesystem::path a, std::filesystem::path b)
{
    std::cout << "relative (" << a << "," << b << ") == ";
    std::cout << std::filesystem::relative(a,b) << "\n";
    std::cout << "proximate(" << a << "," << b << ") == ";
    std::cout << std::filesystem::proximate(a,b) << "\n";
}
int main()
{
    show("/a/b/c","/a/b");
    show("/a/c","/a/b");
    show("c","/a/b");
    show("/a/b","c");
}


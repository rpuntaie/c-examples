/*
g++ --std=c++20 -pthread -o ../_build/cpp/filesystem_space.exe ./cpp/filesystem_space.cpp && (cd ../_build/cpp/;./filesystem_space.exe)
https://en.cppreference.com/w/cpp/filesystem/space
*/
#include <iostream>
#include <filesystem>
#include <cstdint>
void print_space_info(auto const& dirs, int width = 14)
{
    std::cout << std::left;
    for (const auto s : {"Capacity", "Free", "Available", "Dir"})
        std::cout << "│ " << std::setw(width) << s << ' ';
    std::cout << '\n';
    std::error_code ec;
    for (auto const& dir : dirs) {
        const std::filesystem::space_info si = std::filesystem::space(dir, ec);
        std::cout
            << "│ " << std::setw(width) << static_cast<std::intmax_t>(si.capacity) << ' '
            << "│ " << std::setw(width) << static_cast<std::intmax_t>(si.free) << ' '
            << "│ " << std::setw(width) << static_cast<std::intmax_t>(si.available) << ' '
            << "│ " << dir << '\n';
    }
}
int main()
{
    const auto dirs = { "/dev/null", "/tmp", "/home", "/null" };
    print_space_info(dirs);
}


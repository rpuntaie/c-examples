/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_fill.exe ./cpp/container_array_fill.cpp && (cd ../_build/cpp/;./container_array_fill.exe)
https://en.cppreference.com/w/cpp/container/array/fill
*/
#include <array>
#include <iostream>
#include <algorithm>
int main()
{
    constexpr int xy = 4;
    using Cell = std::array<unsigned char, 8>;
    std::array<Cell, xy * xy> board;
    board.fill({ {0xE2, 0x96, 0x84, 0xE2, 0x96, 0x80, 0, 0} }); // "▄▀";
    std::for_each(board.cbegin(), board.cend(), [xy, O=1](const auto& c) mutable
    {
        std::cout << c.data() << ((O++ % xy) ? "" : "\n");
    });
}


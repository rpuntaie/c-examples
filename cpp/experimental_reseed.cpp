/*
g++ --std=c++20 -pthread -o ../_build/cpp/experimental_reseed.exe ./cpp/experimental_reseed.cpp && (cd ../_build/cpp/;./experimental_reseed.exe)
https://en.cppreference.com/w/cpp/experimental/reseed
*/
#include <experimental/random>
#include <iostream>
int main()
{
    std::experimental::reseed();
    std::cout << "Random 2-digit decimal numbers: ";
    for (auto i = 0; i != 3; ++i)
    {
        std::cout << std::experimental::randint(10, 99) << ' ';
    }
}


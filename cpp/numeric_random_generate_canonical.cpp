/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_generate_canonical.exe ./cpp/numeric_random_generate_canonical.cpp && (cd ../_build/cpp/;./numeric_random_generate_canonical.exe)
https://en.cppreference.com/w/cpp/numeric/random/generate_canonical
*/
#include <random>
#include <iostream>
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    for(int n=0; n<10; ++n) {
        std::cout << std::generate_canonical<double, 10>(gen) << ' ';
    }
}


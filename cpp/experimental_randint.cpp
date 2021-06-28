/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_randint.exe ./cpp/experimental_randint.cpp && (cd ../_build/cpp/;./experimental_randint.exe)
https://en.cppreference.com/w/cpp/experimental/randint
*/
#include <iostream>
#include <experimental/random>
int main()
{
    int random_number = std::experimental::randint(100, 999);
    std::cout << "random 3-digit number: " << random_number << '\n';
}


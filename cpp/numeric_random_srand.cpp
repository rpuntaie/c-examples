/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_srand.exe ./cpp/numeric_random_srand.cpp && (cd ../_build/cpp/;./numeric_random_srand.exe)
https://en.cppreference.com/w/cpp/numeric/random/srand
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
int main() 
{
    std::srand(std::time(0)); //use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
}


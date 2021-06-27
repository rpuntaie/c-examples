/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_rand.exe ./cpp/numeric_random_rand.cpp && (cd ../_build/cpp/;./numeric_random_rand.exe)
https://en.cppreference.com/w/cpp/numeric/random/rand
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
int main() 
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
    // roll 6-sided dice 20 times
    for (int n=0; n != 20; ++n) {
        int x = 7;
        while(x > 6) 
            x = 1 + std::rand()/((RAND_MAX + 1u)/6);  // Note: 1+rand()%6 is biased
        std::cout << x << ' ';
    }
}


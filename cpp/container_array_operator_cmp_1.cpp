/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_array_operator_cmp_1.exe ./cpp/container_array_operator_cmp_1.cpp && (cd ../_build/cpp/;./container_array_operator_cmp_1.exe)
https://en.cppreference.com/w/cpp/container/array/operator_cmp
*/
#include <iostream>
#include <array>
int main()
{
    std::array<int, 3> alice{1, 2, 3};
    std::array<int, 3> bob{7, 8, 9};
    std::array<int, 3> eve{1, 2, 3};
    std::cout << std::boolalpha;
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
    std::cout << '\n';
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}


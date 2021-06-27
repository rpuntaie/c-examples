/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_operator_cmp_1.exe ./cpp/container_deque_operator_cmp_1.cpp && (cd ../_build/cpp/;./container_deque_operator_cmp_1.exe)
https://en.cppreference.com/w/cpp/container/deque/operator_cmp
*/
#include <iostream>
#include <deque>
int main()
{
    std::deque<int> alice{1, 2, 3};
    std::deque<int> bob{7, 8, 9, 10};
    std::deque<int> eve{1, 2, 3};
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


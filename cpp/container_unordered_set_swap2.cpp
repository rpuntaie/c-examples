/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_swap2.exe ./cpp/container_unordered_set_swap2.cpp && (cd ../_build/cpp/;./container_unordered_set_swap2.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/swap2
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
int main()
{
    std::unordered_set<int> alice{1, 2, 3};
    std::unordered_set<int> bob{7, 8, 9, 10};
    auto print = [](const int& n) { std::cout << ' ' << n; };
    // Print state before swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);
    // Print state after swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
}


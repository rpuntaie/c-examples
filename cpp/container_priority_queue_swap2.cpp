/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_priority_queue_swap2.exe ./cpp/container_priority_queue_swap2.cpp && (cd ../_build/cpp/;./container_priority_queue_swap2.exe)
https://en.cppreference.com/w/cpp/container/priority_queue/swap2
*/
#include <algorithm>
#include <iostream>
#include <queue>
int main()
{
    std::priority_queue<int> alice;
    std::priority_queue<int> bob;
    auto print = [](const auto & title, const auto &cont) { 
        std::cout << title << " size=" << cont.size();
        std::cout << " top=" << cont.top() << '\n';
    };
    for (int i = 1; i < 4; ++i)
        alice.push(i);
    for (int i = 7; i < 11; ++i)
        bob.push(i);
    // Print state before swap
    print("alice:", alice);
    print("bob  :", bob);
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);
    // Print state after swap
    print("alice:", alice);
    print("bob  :", bob);
}


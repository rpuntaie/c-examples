/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_swap2.exe ./cpp/container_unordered_map_swap2.cpp && (cd ../_build/cpp/;./container_unordered_map_swap2.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/swap2
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_map<int, char> alice{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    std::unordered_map<int, char> bob{{7, 'Z'}, {8, 'Y'}, {9, 'X'}, {10, 'W'}};
    auto print = [](std::pair<const int, char>& n) { 
        std::cout << " " << n.first << '(' << n.second << ')'; 
    };
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


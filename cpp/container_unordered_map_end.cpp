/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_end.exe ./cpp/container_unordered_map_end.cpp && (cd ../_build/cpp/;./container_unordered_map_end.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/end
*/
#include <cmath>
#include <iostream>
#include <unordered_map>
struct Node { double x, y; };
int main() {
    Node nodes[3] = { {1, 0}, {2, 0}, {3, 0} };
    //mag is a map mapping the address of a Node to its magnitude in the plane
    std::unordered_map<Node *, double> mag = {
        { nodes,     1 },
        { nodes + 1, 2 },
        { nodes + 2, 3 }
    };
    //Change each y-coordinate from 0 to the magnitude
    for(auto iter = mag.begin(); iter != mag.end(); ++iter){
        auto cur = iter->first; // pointer to Node
        cur->y = mag[cur]; // could also have used  cur->y = iter->second;
    }
    //Update and print the magnitude of each node
    for(auto iter = mag.begin(); iter != mag.end(); ++iter){
        auto cur = iter->first;
        mag[cur] = std::hypot(cur->x, cur->y);
        std::cout << "The magnitude of (" << cur->x << ", " << cur->y << ") is ";
        std::cout << iter->second << '\n';
    }
    //Repeat the above with the range-based for loop
    for(auto i : mag) {
        auto cur = i.first;
        cur->y = i.second;
        mag[cur] = std::hypot(cur->x, cur->y);
        std::cout << "The magnitude of (" << cur->x << ", " << cur->y << ") is ";
        std::cout << mag[cur] << '\n';
        //Note that in contrast to std::cout << iter->second << '\n'; above, 
        // std::cout << i.second << '\n'; will NOT print the updated magnitude
    }
}


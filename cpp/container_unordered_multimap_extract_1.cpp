/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multimap_extract_1.exe ./cpp/container_unordered_multimap_extract_1.cpp && (cd ../_build/cpp/;./container_unordered_multimap_extract_1.exe)
https://en.cppreference.com/w/cpp/container/unordered_multimap/extract
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_multimap<int, char> cont{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    auto print = [](std::pair<const int, char>& n) { 
        std::cout << " " << n.first << '(' << n.second << ')'; 
    };
    std::cout << "Start:";
    std::for_each(cont.begin(), cont.end(), print);
    std::cout << '\n';
    // Extract node handle and change key
    auto nh = cont.extract(1);
    nh.key() = 4; 
    std::cout << "After extract and before insert:";
    std::for_each(cont.begin(), cont.end(), print);
    std::cout << '\n';
    // Insert node handle back
    cont.insert(move(nh));
    std::cout << "End:";
    std::for_each(cont.begin(), cont.end(), print);
    std::cout << '\n';
}


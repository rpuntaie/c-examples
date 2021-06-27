/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_extract_1.exe ./cpp/container_unordered_set_extract_1.cpp && (cd ../_build/cpp/;./container_unordered_set_extract_1.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/extract
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
int main()
{
    std::unordered_set<int> cont{1, 2, 3};
    auto print = [](const int& n) { std::cout << " " << n; };
    std::cout << "Start:";
    std::for_each(cont.begin(), cont.end(), print);
    std::cout << '\n';
    // Extract node handle and change key
    auto nh = cont.extract(1);
    nh.value() = 4; 
    std::cout << "After extract and before insert:";
    std::for_each(cont.begin(), cont.end(), print);
    std::cout << '\n';
    // Insert node handle back
    cont.insert(move(nh));
    std::cout << "End:";
    std::for_each(cont.begin(), cont.end(), print);
    std::cout << '\n';
}


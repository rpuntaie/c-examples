/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_extract_1.exe ./cpp/container_set_extract_1.cpp && (cd ../_build/cpp/;./container_set_extract_1.exe)
https://en.cppreference.com/w/cpp/container/set/extract
*/
#include <algorithm>
#include <iostream>
#include <set>
int main()
{
    std::set<int> cont{1, 2, 3};
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


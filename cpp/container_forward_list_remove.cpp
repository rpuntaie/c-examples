/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_forward_list_remove.exe ./cpp/container_forward_list_remove.cpp && (cd ../_build/cpp/;./container_forward_list_remove.exe)
https://en.cppreference.com/w/cpp/container/forward_list/remove
*/
#include <forward_list>
#include <iostream>
int main()
{
    std::forward_list<int> l = { 1,100,2,3,10,1,11,-1,12 };
    l.remove(1); // remove both elements equal to 1
    l.remove_if([](int n){ return n > 10; }); // remove all elements greater than 10
    for (int n : l) {
        std::cout << n << ' '; 
    }
    std::cout << '\n';
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_operator_at.exe ./cpp/container_deque_operator_at.cpp && (cd ../_build/cpp/;./container_deque_operator_at.exe)
https://en.cppreference.com/w/cpp/container/deque/operator_at
*/
#include <deque>
#include <iostream>
int main()
{
    std::deque<int> numbers {2, 4, 6, 8};
    std::cout << "Second element: " << numbers[1] << '\n';
    numbers[0] = 5;
    std::cout << "All numbers:";
    for (auto i : numbers) {
        std::cout << ' ' << i;
    }
    std::cout << '\n';
}


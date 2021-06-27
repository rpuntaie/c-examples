/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_deque_pop_front.exe ./cpp/container_deque_pop_front.cpp && (cd ../_build/cpp/;./container_deque_pop_front.exe)
https://en.cppreference.com/w/cpp/container/deque/pop_front
*/
#include <deque>
#include <iostream>
auto print = [](const auto& con) {
    for (auto const& item : con)
        std::cout << item;
    std::cout << '\n';
};
int main() {
    std::deque<char> letters{'A','B','C','D'};
    for (char c{letters.back()}; c != 'H' ;) {
        letters.push_back(++c);
        print(letters);
        letters.pop_front();
    }
}


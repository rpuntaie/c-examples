/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_span_end.exe ./cpp/container_span_end.cpp && (cd ../_build/cpp/;./container_span_end.exe)
https://en.cppreference.com/w/cpp/container/span/end
*/
#include <span>
#include <iostream>
void print(std::span<const int> sp)
{
    for(auto it = sp.begin(); it != sp.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
void transmogrify(std::span<int> sp)
{
    if (!sp.empty()) {
        std::cout << *sp.begin() << '\n';
        *sp.begin() = 2;
    }
}
int main()
{
    int array[] { 1, 3, 4, 5 };
    print(array);
    transmogrify(array);
    print(array);
}


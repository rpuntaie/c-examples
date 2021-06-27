/*
g++ --std=c++20 -pthread -o ../_build/cpp/experimental_list_erase.exe ./cpp/experimental_list_erase.cpp && (cd ../_build/cpp/;./experimental_list_erase.exe)
https://en.cppreference.com/w/cpp/experimental/list/erase
*/
#include <experimental/list>
#include <iostream>
auto show = [](const auto& container) {
    for (auto e : container) {
        std::cout << e;
    }
    std::cout << '\n';
};
int main()
{
    std::list<int> data{1,1,1,4,1,1,1,2,1,1,1};
    show(data);
    std::experimental::erase(data, 1);
    show(data);
}


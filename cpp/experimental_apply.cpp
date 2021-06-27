/*
g++ --std=c++20 -pthread -o ../_build/cpp/experimental_apply.exe ./cpp/experimental_apply.cpp && (cd ../_build/cpp/;./experimental_apply.exe)
https://en.cppreference.com/w/cpp/experimental/apply
*/
#include <iostream>
#include <tuple>
template<typename... Ts>
void print_tuple (const std::tuple<Ts...> &tuple)
{
    std::apply ([] (const auto &... elem) 
                {
                    ((std::cout << elem << '\n'), ...); 
                },
                tuple);
}
int main() {
    const std::tuple<int, char> t = std::make_tuple(5, 'a');
    print_tuple(t);
}


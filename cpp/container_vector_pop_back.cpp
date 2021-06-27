/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_vector_pop_back.exe ./cpp/container_vector_pop_back.cpp && (cd ../_build/cpp/;./container_vector_pop_back.exe)
https://en.cppreference.com/w/cpp/container/vector/pop_back
*/
#include <vector>
#include <iostream>
template<typename T>
void print(T const & xs)
{
    std::cout << "[ ";
    for(auto const & x : xs) {
        std::cout << x << ' ';
    }
    std::cout << "]\n";
}
int main()
{
    std::vector<int> numbers;
    print(numbers); 
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(4);
    print(numbers); 
    numbers.pop_back();
    print(numbers); 
}


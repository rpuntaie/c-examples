/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_shuffle.exe ./cpp/experimental_shuffle.cpp && (cd ../_build/cpp/;./experimental_shuffle.exe)
https://en.cppreference.com/w/cpp/experimental/shuffle
*/
#include <experimental/algorithm>
#include <iostream>
#include <string>
int main()
{
    std::string sample{"ABCDEF"};
    for (int i = 0; i != 4; ++i) {
        std::experimental::shuffle(sample.begin(), sample.end());
        std::cout << sample << '\n';
    }
}


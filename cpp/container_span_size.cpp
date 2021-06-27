/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_span_size.exe ./cpp/container_span_size.cpp && (cd ../_build/cpp/;./container_span_size.exe)
https://en.cppreference.com/w/cpp/container/span/size
*/
#include <iostream>
#include <span>
void show_sizes(std::span<const int> span)
{
    std::cout
        << span                 .size() << ' ' // 8
        << span.first(7)        .size() << ' ' // 7
        << span.first<6>()      .size() << ' ' // 6 
        << span.last(5)         .size() << ' ' // 5 
        << span.last<4>()       .size() << ' ' // 4
        << span.subspan(2, 3)   .size() << ' ' // 3 
        << span.subspan<3, 2>() .size() << ' ' // 2
        << '\n';
}
int main()
{
    int antique_array[] { 1, 2, 3, 4, 5, 6, 7, 8 };
    show_sizes(antique_array);
}


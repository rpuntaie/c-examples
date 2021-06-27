/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_initializer_list_size.exe ./cpp/utility_initializer_list_size.cpp && (cd ../_build/cpp/;./utility_initializer_list_size.exe)
https://en.cppreference.com/w/cpp/utility/initializer_list/size
*/
#include <initializer_list>
int main() { static_assert(std::initializer_list{1,2,3,4}.size() == 4); }


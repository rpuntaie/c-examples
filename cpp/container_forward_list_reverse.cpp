/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_forward_list_reverse.exe ./cpp/container_forward_list_reverse.cpp && (cd ../_build/cpp/;./container_forward_list_reverse.exe)
https://en.cppreference.com/w/cpp/container/forward_list/reverse
*/
#include <iostream>
#include <forward_list>
std::ostream& operator<<(std::ostream& ostr, const std::forward_list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}
int main()
{
    std::forward_list<int> list = { 8,7,5,9,0,1,3,2,6,4 };
    std::cout << "before:     " << list << "\n";
    list.sort();
    std::cout << "ascending:  " << list << "\n";
    list.reverse();
    std::cout << "descending: " << list << "\n";
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_list_merge.exe ./cpp/container_list_merge.cpp && (cd ../_build/cpp/;./container_list_merge.exe)
https://en.cppreference.com/w/cpp/container/list/merge
*/
#include <iostream>
#include <list>
std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}
int main()
{
    std::list<int> list1 = { 5,9,0,1,3 };
    std::list<int> list2 = { 8,7,2,6,4 };
    list1.sort();
    list2.sort();
    std::cout << "list1:  " << list1 << "\n";
    std::cout << "list2:  " << list2 << "\n";
    list1.merge(list2);
    std::cout << "merged: " << list1 << "\n";
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_stable_sort.exe ./cpp/algorithm_stable_sort.cpp && (cd ../_build/cpp/;./algorithm_stable_sort.exe)
https://en.cppreference.com/w/cpp/algorithm/stable_sort
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct Employee
{
    int age;
    std::string name;  // Does not participate in comparisons
};
bool operator<(const Employee & lhs, const Employee & rhs)
{
    return lhs.age < rhs.age;
}
int main()
{
    std::vector<Employee> v =
    { 
        {108, "Zaphod"},
        {32, "Arthur"},
        {108, "Ford"},
    };  
    std::stable_sort(v.begin(), v.end());
    for (const Employee & e : v)
        std::cout << e.age << ", " << e.name << '\n';
}


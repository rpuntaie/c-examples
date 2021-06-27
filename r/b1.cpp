/*
g++ -std=c++20 -o ../_build/r/b1.exe r/b1.cpp && (cd ../_build/r;./b1.exe)
*/

#include <string>
#include <iostream>
using namespace std;
template<typename... Args>
auto sum(Args... args)
{
    return (args + ... + 0);
}
template <typename... Args>
auto sum2(Args... args)
{
    return (args + ...);
}
void sum()
{
    // Function Calls
    cout << sum(11, 22, 33, 44, 55)
         << "\n";
    cout << sum2(11, 22, 33, 44, 55)
         << "\n";
}
template<class... T>
decltype(auto) difference(T... args)
{
 // Unpacks to: ...(a1 - a2) - a3
 return (... - args);
}
void mins()
{
     cout << difference(5, 2, 1); // "2" (5-2-1)
}
int main()
{
    sum();
    mins();
}

/*
g++ --std=c++20 -pthread -o ../_build/cpp/iterator_empty.exe ./cpp/iterator_empty.cpp && (cd ../_build/cpp/;./iterator_empty.exe)
https://en.cppreference.com/w/cpp/iterator/empty
*/
#include <iostream>
#include <vector>
template <class T>
void print(const T& container)
{
    if ( std::empty(container) )
    {
        std::cout << "Empty\n";
    }
    else
    {
        std::cout << "Elements:";
        for ( const auto& element : container )
            std::cout << ' ' << element;
        std::cout << '\n';
    }
}
int main() 
{
    std::vector<int> c = { 1, 2, 3 };
    print(c);
    c.clear();
    print(c);
    int array[] = { 4, 5, 6 };
    print(array);
    auto il = { 7, 8, 9 };
    print(il);
}


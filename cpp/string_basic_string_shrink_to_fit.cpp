/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_shrink_to_fit.exe ./cpp/string_basic_string_shrink_to_fit.cpp && (cd ../_build/cpp/;./string_basic_string_shrink_to_fit.exe)
https://en.cppreference.com/w/cpp/string/basic_string/shrink_to_fit
*/
#include <iostream>
#include <string>
int main()
{
    std::string s;
    std::cout << "Default-constructed capacity is " << s.capacity() 
        << " and size is " << s.size() << '\n';
    for (int i=0; i<42; i++)
        s.append(" 42 ");
    std::cout << "Capacity after a couple of appends is " << s.capacity() 
        << " and size is " << s.size() << '\n';
    s.clear();
    std::cout << "Capacity after clear() is " << s.capacity() 
        << " and size is " << s.size() << '\n';
    s.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << s.capacity() 
        << " and size is " << s.size() << '\n';
}


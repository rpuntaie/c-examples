/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_escape.exe ./cpp/language_escape.cpp && (cd ../_build/cpp/;./language_escape.exe)
https://en.cppreference.com/w/cpp/language/escape
*/
#include <iostream>
int main()
{
    std::cout << "This\nis\na\ntest\n\nShe said, \"Sells she seashells on the seashore?\"\n";
}


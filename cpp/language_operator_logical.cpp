/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_operator_logical.exe ./cpp/language_operator_logical.cpp && (cd ../_build/cpp/;echo quit | ./language_operator_logical.exe)
https://en.cppreference.com/w/cpp/language/operator_logical
*/
#include <iostream>
#include <string>
int main()
{
    int n = 2;
    int* p = &n;
    // pointers are convertible to bool
    if(    p && *p == 2   // "*p" is safe to use after "p &&"
       || !p &&  n != 2 ) // || has lower precedence than &&
        std::cout << "true\n";
    // streams are also convertible to bool
    std::cout << "Enter 'quit' to quit.\n";
    for(std::string line;    std::cout << "> "
                          && std::getline(std::cin, line)
                          && line != "quit"; )
        ;
}


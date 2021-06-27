/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_operator_bool.exe ./cpp/memory_shared_ptr_operator_bool.cpp && (cd ../_build/cpp/;./memory_shared_ptr_operator_bool.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/operator_bool
*/
#include <iostream>
#include <memory>
void report(std::shared_ptr<int> ptr) 
{
    if (ptr) {
        std::cout << "*ptr=" << *ptr << "\n";
    } else {
        std::cout << "ptr is not a valid pointer.\n";
    }
}
int main()
{
    std::shared_ptr<int> ptr;
    report(ptr);
    ptr = std::make_shared<int>(7);
    report(ptr);
}


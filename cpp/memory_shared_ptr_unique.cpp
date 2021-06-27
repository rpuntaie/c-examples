/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_unique.exe ./cpp/memory_shared_ptr_unique.cpp && (cd ../_build/cpp/;./memory_shared_ptr_unique.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/unique
*/
#include <memory> 
#include <iostream> 
int main() 
{ 
    auto sp1 = std::make_shared<int>(5);
    std::cout << std::boolalpha;
    std::cout << "sp1.unique() == " << sp1.unique() << '\n'; 
    std::shared_ptr<int> sp2 = sp1; 
    std::cout << "sp1.unique() == " << sp1.unique() << '\n'; 
}


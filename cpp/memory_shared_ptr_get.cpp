/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_get.exe ./cpp/memory_shared_ptr_get.cpp && (cd ../_build/cpp/;./memory_shared_ptr_get.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/get
*/
#include <iostream>
#include <memory>
#include <string_view>
void output(std::string_view msg, int const* pInt)
{
    std::cout << msg << *pInt << " in " << pInt << "\n";
}
int main()
{
    int* pInt = new int(42);
    std::shared_ptr<int> pShared = std::make_shared<int>(42);
    output("Naked pointer ", pInt);
    // output("Shared pointer ", pShared); // compiler error
    output("Shared pointer with get() ", pShared.get());
    delete pInt;
}


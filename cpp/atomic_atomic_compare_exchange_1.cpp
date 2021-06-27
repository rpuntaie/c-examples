/*
g++ --std=c++20 -pthread -o ../_build/cpp/atomic_atomic_compare_exchange_1.exe ./cpp/atomic_atomic_compare_exchange_1.cpp && (cd ../_build/cpp/;./atomic_atomic_compare_exchange_1.exe)
https://en.cppreference.com/w/cpp/atomic/atomic/compare_exchange
*/
#include <atomic>
#include <iostream>
std::atomic<int>  ai;
int  tst_val= 4;
int  new_val= 5;
bool exchanged= false;
void valsout()
{
    std::cout << "ai= " << ai
          << "  tst_val= " << tst_val
          << "  new_val= " << new_val
          << "  exchanged= " << std::boolalpha << exchanged
          << "\n";
}
int main()
{
    ai= 3;
    valsout();
    // tst_val != ai   ==>  tst_val is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    valsout();
    // tst_val == ai   ==>  ai is modified
    exchanged= ai.compare_exchange_strong( tst_val, new_val );
    valsout();
}


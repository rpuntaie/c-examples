/*
g++ --std=c++20 -latomic -pthread -o ../_build/cpp/atomic_ATOMIC_FLAG_INIT.exe ./cpp/atomic_ATOMIC_FLAG_INIT.cpp && (cd ../_build/cpp/;./atomic_ATOMIC_FLAG_INIT.exe)
https://en.cppreference.com/w/cpp/atomic/ATOMIC_FLAG_INIT
*/
#include <atomic>
std::atomic_flag static_flag = ATOMIC_FLAG_INIT; // static initialization,
// guaranteed to be available during dynamic initialization of static objects.
int main()
{
    std::atomic_flag automatic_flag = ATOMIC_FLAG_INIT; // guaranteed to work
//    std::atomic_flag another_flag(ATOMIC_FLAG_INIT); // unspecified
}


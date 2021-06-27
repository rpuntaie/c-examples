/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_storage_duration_1.exe ./cpp/language_storage_duration_1.cpp && (cd ../_build/cpp/;./language_storage_duration_1.exe)
https://en.cppreference.com/w/cpp/language/storage_duration
*/
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
thread_local unsigned int rage = 1; 
std::mutex cout_mutex;
void increase_rage(const std::string& thread_name)
{
    ++rage; // modifying outside a lock is okay; this is a thread-local variable
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}
int main()
{
    std::thread a(increase_rage, "a"), b(increase_rage, "b");
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Rage counter for main: " << rage << '\n';
    }
    a.join();
    b.join();
}


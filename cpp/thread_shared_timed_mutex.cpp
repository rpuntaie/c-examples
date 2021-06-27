/*
g++ --std=c++20 -pthread -o ../_build/cpp/thread_shared_timed_mutex.exe ./cpp/thread_shared_timed_mutex.cpp && (cd ../_build/cpp/;./thread_shared_timed_mutex.exe)
https://en.cppreference.com/w/cpp/thread/shared_timed_mutex
*/
#include <mutex>
#include <shared_mutex>
class R
{
    mutable std::shared_timed_mutex mut;
    /* data */
public:
    R& operator=(const R& other)
    {
        // requires exclusive ownership to write to *this
        std::unique_lock<std::shared_timed_mutex> lhs(mut, std::defer_lock);
        // requires shared ownership to read from other
        std::shared_lock<std::shared_timed_mutex> rhs(other.mut, std::defer_lock);
        std::lock(lhs, rhs);
        /* assign data */
        return *this;
    }
};
int main() {
    R r;
}


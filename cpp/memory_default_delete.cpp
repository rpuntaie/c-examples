/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_default_delete.exe ./cpp/memory_default_delete.cpp && (cd ../_build/cpp/;./memory_default_delete.exe)
https://en.cppreference.com/w/cpp/memory/default_delete
*/
#include <memory>
#include <vector>
#include <algorithm>
int main()
{
//    {
//        std::shared_ptr<int> shared_bad(new int[10]);
//    } // the destructor calls delete, undefined behavior
    {
        std::shared_ptr<int> shared_good(new int[10], std::default_delete<int[]>());
    } // the destructor calls delete[], ok
    {
        std::unique_ptr<int> ptr(new int(5));
    } // unique_ptr<int> uses default_delete<int>
    {
        std::unique_ptr<int[]> ptr(new int[10]);
    } // unique_ptr<int[]> uses default_delete<int[]>
    // default_delete can be used anywhere a delete functor is needed
    std::vector<int*> v;
    for(int n = 0; n < 100; ++n)
        v.push_back(new int(n));
    std::for_each(v.begin(), v.end(), std::default_delete<int>());
}


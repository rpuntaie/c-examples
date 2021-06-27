/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_ranges_partition.exe ./cpp/algorithm_ranges_partition.cpp && (cd ../_build/cpp/;./algorithm_ranges_partition.exe)
https://en.cppreference.com/w/cpp/algorithm/ranges/partition
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>
namespace ranges = std::ranges;
template <std::permutable I, std::sentinel_for<I> S>
void quicksort(I first, S last)
{
   if(first == last) {
       return;
   }
   auto pivot = *ranges::next(first, ranges::distance(first,last)/2, last);
   std::ranges::subrange tail1 = ranges::partition(first, last, [pivot](const auto& em){
       return em < pivot;
   });
   std::ranges::subrange tail2 = ranges::partition(tail1, [pivot](const auto& em){
       return !(pivot < em);
   });
   quicksort(first, tail1.begin());
   quicksort(tail2.begin(), tail2.end());
}
int main()
{
    std::ostream_iterator<int> cout {std::cout, " "};
    std::vector<int> v {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Original vector:\n\t";
    ranges::copy(v, cout);
    auto tail = ranges::partition(v, [](int i){return i % 2 == 0;});
    std::cout << "\nPartitioned vector:\n\t";
    ranges::copy(ranges::begin(v), ranges::begin(tail), cout);
    std::cout << "* ";
    ranges::copy(tail, cout);
    std::forward_list<int> fl {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    std::cout << "\nUnsorted list:\n\t";
    ranges::copy(fl, cout);
    quicksort(ranges::begin(fl), ranges::end(fl));
    std::cout << "\nSorted using quicksort:\n\t";
    ranges::copy(fl, cout);
    std::cout << '\n';
}


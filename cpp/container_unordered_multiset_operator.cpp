/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_multiset_operator.exe ./cpp/container_unordered_multiset_operator.cpp && (cd ../_build/cpp/;./container_unordered_multiset_operator.exe)
https://en.cppreference.com/w/cpp/container/unordered_multiset/operator=
*/
#include <unordered_set>
#include <iostream>
void display_sizes(const std::unordered_multiset<int> &nums1,
                   const std::unordered_multiset<int> &nums2,
                   const std::unordered_multiset<int> &nums3)
{
    std::cout << "nums1: " << nums1.size() 
              << " nums2: " << nums2.size()
              << " nums3: " << nums3.size() << '\n';
}
int main()
{
    std::unordered_multiset<int> nums1 {3, 1, 4, 6, 5, 9};
    std::unordered_multiset<int> nums2; 
    std::unordered_multiset<int> nums3;
    std::cout << "Initially:\n";
    display_sizes(nums1, nums2, nums3);
    // copy assignment copies data from nums1 to nums2
    nums2 = nums1;
    std::cout << "After assigment:\n"; 
    display_sizes(nums1, nums2, nums3);
    // move assignment moves data from nums1 to nums3,
    // modifying both nums1 and nums3
    nums3 = std::move(nums1);
    std::cout << "After move assigment:\n"; 
    display_sizes(nums1, nums2, nums3);
}


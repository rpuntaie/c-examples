/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_set_deduction_guides.exe ./cpp/container_unordered_set_deduction_guides.cpp && (cd ../_build/cpp/;./container_unordered_set_deduction_guides.exe)
https://en.cppreference.com/w/cpp/container/unordered_set/deduction_guides
*/
#include <unordered_set>
int main() {
   std::unordered_set s = {1,2,3,4};            // guide #2 deduces std::unordered_set<int>
   std::unordered_set s2(s.begin(), s.end());   // guide #1 deduces std::unordered_set<int>
}


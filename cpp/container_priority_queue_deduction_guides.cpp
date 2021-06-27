/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_priority_queue_deduction_guides.exe ./cpp/container_priority_queue_deduction_guides.cpp && (cd ../_build/cpp/;./container_priority_queue_deduction_guides.exe)
https://en.cppreference.com/w/cpp/container/priority_queue/deduction_guides
*/
#include <functional>
#include <vector>
#include <queue>
int main() {
   std::vector<int> v = {1,2,3,4};
   std::priority_queue pq1{std::greater<int>{}, v}; // deduces std::priority_queue<
                                                    //   int, std::vector<int>,
                                                    //   std::greater<int>>
   std::priority_queue pq2{v.begin(), v.end()}; // deduces std::priority_queue<int>
}


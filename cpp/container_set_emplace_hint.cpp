/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_set_emplace_hint.exe ./cpp/container_set_emplace_hint.cpp && (cd ../_build/cpp/;./container_set_emplace_hint.exe)
https://en.cppreference.com/w/cpp/container/set/emplace_hint
*/
#include <set>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <functional>
const int nof_operations = 100500;
int set_emplace() {
  std::set<int> set;
  for(int i = 0; i < nof_operations; ++i) {
    set.emplace(i);
  }
  return set.size();
}
int set_emplace_hint() {
  std::set<int> set;
  auto it = set.begin();
  for(int i = 0; i < nof_operations; ++i) {
    set.emplace_hint(it, i);
    it = set.end();
  }
  return set.size();
}
int set_emplace_hint_wrong() {
  std::set<int> set;
  auto it = set.begin();
  for(int i = nof_operations; i > 0; --i) {
    set.emplace_hint(it, i);
    it = set.end();
  }
  return set.size();
}
int set_emplace_hint_corrected() {
  std::set<int> set;
  auto it = set.begin();
  for(int i = nof_operations; i > 0; --i) {
    set.emplace_hint(it, i);
    it = set.begin();
  }
  return set.size();
}
int set_emplace_hint_closest() {
  std::set<int> set;
  auto it = set.begin();
  for(int i = 0; i < nof_operations; ++i) {
    it = set.emplace_hint(it, i);
  }
  return set.size();
}
void timeit(std::function<int()> set_test, std::string what = "") {
  auto start = std::chrono::system_clock::now();
  int setsize = set_test();
  auto stop = std::chrono::system_clock::now();
  std::chrono::duration<double, std::milli> time = stop - start;
  if (what.size() > 0 && setsize > 0) {
    std::cout << std::fixed << std::setprecision(2) << std::setw(5)
              << time.count() << "  ms for " << what << '\n';
  }
}
int main() {
   timeit(set_emplace); // stack warmup
   timeit(set_emplace, "plain emplace");
   timeit(set_emplace_hint, "emplace with correct hint");
   timeit(set_emplace_hint_wrong, "emplace with wrong hint");
   timeit(set_emplace_hint_corrected, "corrected emplace");
   timeit(set_emplace_hint_closest, "emplace using returned iterator");
}


/*
g++ -std=c++20 -ltbb -o ../_build/r/ce.exe r/ce.cpp && (cd ../_build/r;./ce.exe)
*/
//https://solarianprogrammer.com/2019/05/09/cpp-17-stl-parallel-algorithms-gcc-intel-tbb-linux-macos/
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <execution>

void printDuration(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end, const char *message) {
        auto diff = end - start;
        std::cout << message << ' ' << std::chrono::duration <double, std::milli> (diff).count() << " ms\n";
}

template<typename T>
void test(const T &policy, const std::vector<double> &data, const int repeat, const char *message) {
    for(int i = 0; i < repeat; ++i) {
        std::vector<double> curr_data(data);

        const auto start = std::chrono::steady_clock::now();
        std::sort(policy, curr_data.begin(), curr_data.end());
        const auto end = std::chrono::steady_clock::now();
        printDuration(start, end, message);
    }
    std::cout << '\n';
}

int main() {
    // Test samples and repeat factor
    constexpr size_t samples{5'000'000};
    constexpr int repeat{10};

    // Fill a vector with samples numbers
    std::random_device rd;
    std::mt19937_64 mre(rd());
    std::uniform_real_distribution<double> urd(0.0, 1.0);

    std::vector<double> data(samples);
    for(auto &e : data) {
        e = urd(mre);
    }

    // Sort data using different execution policies
    std::cout << "std::execution::seq\n";
    test(std::execution::seq, data, repeat, "Elapsed time");

    std::cout << "std::execution::par\n";
    test(std::execution::par, data, repeat, "Elapsed time");
}

/* parallel
std::adjacent_difference        std::adjacent_find              std::all_of
std::any_of                     std::copy                       std::copy_if
std::copy_n                     std::count                      std::count_if
std::equal                      std::exclusive_scan             std::fill
std::fill_n                     std::find                       std::find_end
std::find_first_of              std::find_if                    std::find_if_not
std::for_each                   std::for_each_n                 std::generate
std::generate_n                 std::includes                   std::inclusive_scan
std::inner_product              std::inplace_merge              std::is_heap
std::is_heap_until              std::is_partitioned             std::is_sorted
std::is_sorted_until            std::lexicographical_compare    std::max_element
std::merge                      std::min_element                std::minmax_element
std::mismatch                   std::move                       std::none_of
std::nth_element                std::partial_sort               std::partial_sort_copy
std::partition                  std::partition_copy             std::reduce
std::remove                     std::remove_copy                std::remove_copy_if
std::remove_if                  std::replace                    std::replace_copy
std::replace_copy_if            std::replace_if                 std::reverse
std::reverse_copy               std::rotate                     std::rotate_copy
std::search                     std::search_n                   std::set_difference
std::set_intersection           std::set_symmetric_difference   std::set_union
std::sort                       std::stable_partition           std::stable_sort
std::swap_ranges                std::transform                  std::transform_exclusive_scan
std::transform_inclusive_scan   std::transform_reduce           std::uninitialized_copy
std::uninitialized_copy_n       std::uninitialized_fill         std::uninitialized_fill_n
std::unique                     std::unique_copy
*/

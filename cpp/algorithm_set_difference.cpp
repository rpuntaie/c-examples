/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_set_difference.exe ./cpp/algorithm_set_difference.cpp && (cd ../_build/cpp/;./algorithm_set_difference.exe)
https://en.cppreference.com/w/cpp/algorithm/set_difference
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string_view>
#include <vector>
auto print = [](const auto& v, std::string_view end = "") {
    std::cout << "{ ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << "} " << end;
};
struct Order // a struct with some interesting data
{
    int order_id;
    friend std::ostream& operator<<(std::ostream& os, const Order& ord) {
        return os << ord.order_id << ',';
    }
};
int main() {
    const std::vector<int> v1 {1, 2, 5, 5, 5, 9};
    const std::vector<int> v2 {2, 5, 7};
    std::vector<int> diff;
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                        std::inserter(diff, diff.begin()));
    print(v1, "∖ ");
    print(v2, "= ");
    print(diff, "\n");
    // we want to know which orders "cut" between old and new states:
    std::vector<Order> old_orders { {1}, {2}, {5}, {9} };
    std::vector<Order> new_orders { {2}, {5}, {7} };
    std::vector<Order> cut_orders;
    std::set_difference(old_orders.begin(), old_orders.end(),
                        new_orders.begin(), new_orders.end(),
                        std::back_inserter(cut_orders),
                        [](auto& a, auto& b) { return a.order_id < b.order_id; });
    std::cout << "old orders = "; print(old_orders, "\n");
    std::cout << "new orders = "; print(new_orders, "\n");
    std::cout << "cut orders = "; print(cut_orders, "\n");
}


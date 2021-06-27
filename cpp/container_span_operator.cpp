/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_span_operator.exe ./cpp/container_span_operator.cpp && (cd ../_build/cpp/;./container_span_operator.exe)
https://en.cppreference.com/w/cpp/container/span/operator=
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <span>
#include <string_view>
void print(std::string_view info = "", std::span<const int> span = {},
           std::size_t extent = 0, std::size_t size_of = 0) {
    if (span.size() == 0) {
        std::cout << info << '\n';    
        return;
    }
    std::cout << info << '[' << span.size() << "] {";
    std::ranges::for_each(span, [](const int x) { std::cout << ' ' << x; });
    std::cout << " }";
    if (extent != 0) {
        std::cout << " extent = ";
        if (extent == std::dynamic_extent)
            std::cout << "dynamic";
        else
            std::cout << extent;
    }
    if (size_of != 0) {
        std::cout << ", sizeof = " << size_of;
    }
    std::cout << '\n';
}
int main()
{
    std::array<int,6> a1;
    std::array<int,6> a2;
    a1.fill(3);
    a2.fill(4);
    auto s1 = std::span(a1);
    auto s2 = std::span(a2);
    print("s1", s1, s1.extent, sizeof(s1));
    print("s2", s2, s2.extent, sizeof(s2));
    // Check that assignment performs a shallow copy.
    s1 = s2;
    (s1.data() == s2.data() && s1.size() == s2.size())
        ? print("s1 = s2; is a shallow copy!")
        : print("s1 = s2; is a deep copy!");
    print("s1", s1);
    print("Fill s1 with 5:");
    std::ranges::fill(s1, 5);
    // s2 is also 'updated' since s1 and s2 point to the same data
    assert(std::ranges::equal(s1, s2));
    print("s1", s1);
    print("s2", s2);
    print();
    int a3[] {1, 2, 3, 4};
    int a4[] {2, 3, 4, 5};
    int a5[] {3, 4, 5};
    std::span<int, std::dynamic_extent> dynamic_1 {a3};
    std::span<int, std::dynamic_extent> dynamic_2 {a4, 3};
    std::span<int, 4> static_1 {a3};
    std::span<int, 4> static_2 {a4};
    std::span<int, 3> static_3 {a5};
    print("dynamic_1", dynamic_1, dynamic_1.extent, sizeof(dynamic_1));
    print("dynamic_2", dynamic_2, dynamic_2.extent, sizeof(dynamic_2));
    print("static_1", static_1, static_1.extent, sizeof(static_1));
    print("static_2", static_2, static_2.extent, sizeof(static_2));
    print("static_3", static_3, static_3.extent, sizeof(static_3));
    dynamic_1 = dynamic_2; // OK
    dynamic_1 = static_1;  // OK
 // static_1  = dynamic_1; // ERROR: no match for ‘operator=’
    static_1  = static_2;  // OK: same extents = 4
 // static_1  = static_3;  // ERROR: different extents: 4 and 3
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_ranges_uninitialized_move_n_1.exe ./cpp/memory_ranges_uninitialized_move_n_1.cpp && (cd ../_build/cpp/;./memory_ranges_uninitialized_move_n_1.exe)
https://en.cppreference.com/w/cpp/memory/ranges/uninitialized_move_n
*/
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
void print(auto rem, auto first, auto last) {
    for (std::cout << rem; first != last; ++first)
        std::cout << std::quoted(*first) << ' ';
    std::cout << '\n';
}
int main() {
    std::string in[] { "No", "Diagnostic", "Required", };
    print("initially, in: ", std::begin(in), std::end(in));
    if (
        constexpr auto sz = std::size(in);
        void* out = std::aligned_alloc(alignof(std::string), sizeof(std::string) * sz)
    ) {
        try {
            auto first {static_cast<std::string*>(out)};
            auto last {first + sz};
            std::ranges::uninitialized_move_n(std::begin(in), sz, first, last);
            print("after move, in: ", std::begin(in), std::end(in));
            print("after move, out: ", first, last);
            std::ranges::destroy(first, last);
        }
        catch (...) {
            std::cout << "Exception!\n";
        }
        std::free(out);
    }
}

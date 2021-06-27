/*
g++ -std=c++20 -o ../_build/r/ga.exe r/ga.cpp && (cd ../_build/r;./ga.exe)
*/

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <span>

void copy_n(const int* src, int* des, int n){}
void copy(std::span<const int> src, std::span<int> des){}
void m1(){
    int arr1[] = {1, 2, 3};
    int arr2[] = {3, 4, 5};
    copy_n(arr1, arr2, 3);
    copy(arr1, arr2);
}

template<class T, std::size_t N> [[nodiscard]]
constexpr auto slide(std::span<T,N> s, std::size_t offset, std::size_t width) {
    return s.subspan(offset, offset + width <= s.size() ? width : 0U);
}
 
template<class T, std::size_t N, std::size_t M> [[nodiscard]]
constexpr bool starts_with(std::span<T,N> data, std::span<T,M> prefix) {
    return data.size() >= prefix.size() 
        && std::equal(prefix.begin(), prefix.end(), data.begin());
}
 
template<class T, std::size_t N, std::size_t M> [[nodiscard]]
constexpr bool ends_with(std::span<T,N> data, std::span<T,M> suffix) {
    return data.size() >= suffix.size() 
        && std::equal(data.end() - suffix.size(), data.end(), 
                      suffix.end() - suffix.size());
}
 
template<class T, std::size_t N, std::size_t M> [[nodiscard]]
constexpr bool contains(std::span<T,N> span, std::span<T,M> sub) {
    return std::search(span.begin(), span.end(), sub.begin(), sub.end()) != span.end();
//  return std::ranges::search(span, sub).begin() != span.end();
}
 
void print(const auto& seq) {
    for (const auto& elem : seq) std::cout << elem << ' ';
    std::cout << '\n';
}
 
void m2()
{
    constexpr int a[] { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    constexpr int b[] { 8, 7, 6 };
 
    //std::span{a+6,3}; // 6,7,8

    for (std::size_t offset{}; ; ++offset) {
        constexpr std::size_t width{6};
        auto s = slide(std::span{a}, offset, width);
        if (s.empty())
            break;
        print(s);
    }
 
    static_assert(starts_with(std::span{a}, std::span{a,4})
        && starts_with(std::span{a+1, 4}, std::span{a+1,3})
        && !starts_with(std::span{a}, std::span{b})
        && !starts_with(std::span{a,8}, std::span{a+1,3})
        && ends_with(std::span{a}, std::span{a+6,3})
        && !ends_with(std::span{a}, std::span{a+6,2})
        && contains(std::span{a}, std::span{a+1,4})
        && !contains(std::span{a,8}, std::span{a,9}));
}

int main()
{
    m1();
    m2();
}


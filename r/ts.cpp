/*
clang -std=c++20 -o ../_build/r/ts.o -c r/ts.cpp
// g++ -std=c++20 -o ../_build/r/ts.o -c r/ts.cpp
*/

#include <type_traits>
#include <map>
#include <vector>

struct S1{
    // ill-formed until C++20 because implicit constructor is noexcept(true)
    S1(S1&&)noexcept(false) = default; // can throw
};
struct S2{
    S2(S2&&) noexcept = default;
    // implicitly generated move constructor would be `noexcept(false)`
    // because of `s1`, now it's enforced to be `noexcept(true)`
    S1 s1;
};
static_assert(std::is_nothrow_move_constructible_v<S1> == false);
static_assert(std::is_nothrow_move_constructible_v<S2> == true);
struct X1{
    X1(X1&&) noexcept = default;
    std::map<int, int> m;   // `std::map(std::map&&)` can throw
};
struct X2{
    // same as implicitly generated, it's `noexcept(false)` because of `std::map`
    X2(X2&&) = default;
    std::map<int, int> m;   // `std::map(std::map&&)` can throw
};
void x(){
std::vector<X1> v1;
std::vector<X2> v2;
// //... at some point, `push_back()` needs to reallocate storage
// //efficiently uses `X1(X1&&)` to move the elements to a new storage,
// //calls `std::terminate()` if it throws
// v1.push_back(X1{});
// //uses `X2(const X2&)`, thus, copies, not moves elements to a new storage
// v2.push_back(X2{});
}

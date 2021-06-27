/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_tuple_operator.exe ./cpp/utility_tuple_operator.cpp && (cd ../_build/cpp/;./utility_tuple_operator.exe)
https://en.cppreference.com/w/cpp/utility/tuple/operator=
*/
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
// helper function to print std::vector
template<class Os, class T> Os& operator<< (Os& os, std::vector<T> const& v) {
    os << "{";
    for (std::size_t t = 0; t != v.size(); ++t)
        os << v[t] << (t+1 < v.size() ? ",":"");
    return os << "}";
}
// helpers to print a tuple of any size
template<class Os, class Tuple, std::size_t N>
struct TuplePrinter {
    static void print(Os& os, const Tuple& t) {
        TuplePrinter<Os, Tuple, N-1>::print(os, t);
        os << ", " << std::get<N-1>(t);
    }
};
template<class Os, class Tuple>
struct TuplePrinter<Os, Tuple, 1>{
    static void print(Os& os, const Tuple& t) {
        os << std::get<0>(t);
    }
};
template<class Os, class... Args>
Os& operator<< (Os& os, const std::tuple<Args...>& t) {
    os << "{ ";
    TuplePrinter<Os, decltype(t), sizeof...(Args)>::print(os, t);
    return os << " }";
}
struct line{ int len{60}; };
template<class Os> Os& operator<< (Os& os, line l) {
    while (l.len-- > 0) std::cout << "─";
    return os << '\n';
}
int main() {
    std::tuple<int, std::string, std::vector<int>>
        t1{1, "alpha", {1, 2, 3} }, t2{2, "beta", {4, 5} };
    std::cout << "t1 = " << t1 << ", t2 = " << t2 << '\n';
    t1 = t2; // (1) operator=( const tuple& other );
    std::cout << "t1 = t2;\n" "t1 = " << t1 << ", t2 = " << t2 << '\n' << line{};
    t1 = std::move(t2); // (2) operator=( tuple&& other );
    std::cout << "t1 = std::move(t2);\n" "t1 = " << t1 << ", t2 = " << t2 << '\n' << line{};
    std::tuple<short, const char*, std::vector<int>> t3{3, "gamma", {6,7,8} };
    t1 = t3; // (3) operator=( const tuple<UTypes...>& other );
    std::cout << "t1 = t3; \n" "t1 = " << t1 << ", t3 = " << t3 << '\n' << line{};
    t1 = std::move(t3); // (4) operator=( tuple<UTypes...>&& other );
    std::cout << "t1 = std::move(t3);\n" "t1 = " << t1 << ", t3 = " << t3 << '\n' << line{};
    std::tuple<std::string, std::vector<int>> t4{"delta", {10,11,12} };
    std::pair<const char*, std::vector<int>> p1{"epsilon", {14,15,16} };
    std::cout << "t4 = " << t4 << ", "
              << "p1 = { " << p1.first << ", " << p1.second << " };\n";
    t4 = p1; // (5) operator=( const std::pair<U1,U2>& p );
    std::cout << "t4 = p1;\n" "t4 = " << t4
              << ", p1 = { " << p1.first << ", " << p1.second << " };\n" << line{};
    t4 = std::move(p1); // (6) operator=( std::pair<U1,U2>&& p );
    std::cout << "t4 = std::move(p1);\n" "t4 = " << t4
              << ", p1 = { " << p1.first << ", " << p1.second << " };\n";
}


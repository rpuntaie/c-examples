/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_functional_bind.exe ./cpp/utility_functional_bind.cpp && (cd ../_build/cpp/;./utility_functional_bind.exe)
https://en.cppreference.com/w/cpp/utility/functional/bind
*/
#include <random>
#include <iostream>
#include <memory>
#include <functional>
void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}
int g(int n1)
{
    return n1;
}
struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    int data = 10;
};
int main()
{
    using namespace std::placeholders;  // for _1, _2, _3...
    std::cout << "demonstrates argument reordering and pass-by-reference:\n";
    int n = 7;
    // (_1 and _2 are from std::placeholders, and represent future
    // arguments that will be passed to f1)
    auto f1 = std::bind(f, _2, 42, _1, std::cref(n), n);
    n = 10;
    f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused
                    // makes a call to f(2, 42, 1, n, 7)
    std::cout << "achieving the same effect using a lambda:\n";
    auto lambda = [ncref=std::cref(n), n=n](auto a, auto b, auto /*unused*/) {
        f(b, 42, a, ncref, n);
    };
    lambda(1, 2, 1001); // same as a call to f1(1, 2, 1001)
    std::cout << "nested bind subexpressions share the placeholders:\n";
    auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
    f2(10, 11, 12); // makes a call to f(12, g(12), 12, 4, 5);
    std::cout << "common use case: binding a RNG with a distribution:\n";
    std::default_random_engine e;
    std::uniform_int_distribution<> d(0, 10);
    auto rnd = std::bind(d, e); // a copy of e is stored in rnd
    for(int n=0; n<10; ++n)
        std::cout << rnd() << ' ';
    std::cout << '\n';
    std::cout << "bind to a pointer to member function:\n";
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
    f3(5);
    std::cout << "bind to a pointer to data member:\n";
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(foo) << '\n';
    std::cout << "use smart pointers to call members of the referenced objects:\n";
    std::cout << f4(std::make_shared<Foo>(foo)) << ' '
              << f4(std::make_unique<Foo>(foo)) << '\n';
}


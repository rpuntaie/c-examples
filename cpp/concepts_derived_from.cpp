/*
g++ --std=c++20 -pthread -o ../_build/cpp/concepts_derived_from.exe ./cpp/concepts_derived_from.cpp && (cd ../_build/cpp/;./concepts_derived_from.exe)
https://en.cppreference.com/w/cpp/concepts/derived_from
*/
#include <concepts>
class A {};
class B: public A {};
class C: private A{};
int main() {
    // std::derived_from == true only for public inheritance or exact same class
    static_assert( std::derived_from<B, B> == true );      // same class: true
    static_assert( std::derived_from<int, int> == false ); // same primitive type: false
    static_assert( std::derived_from<B, A> == true );      // public inheritance: true
    static_assert( std::derived_from<C, A> == false );     // private inheritance: false
    // std::is_base_of == true also for private inheritance
    static_assert( std::is_base_of_v<B, B> == true );      // same class: true
    static_assert( std::is_base_of_v<int, int> == false ); // same primitive type: false
    static_assert( std::is_base_of_v<A, B> == true );      // public inheritance: true
    static_assert( std::is_base_of_v<A, C> == true );      // private inheritance: true
}


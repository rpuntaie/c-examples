/*
g++ -std=c++20 -o ../_build/r/ta.o -c r/ta.cpp
*/

#include <concepts>

template<typename T>
concept Addable = requires(T a, T b) { a + b; };
template<typename T>
concept Subtractable = requires(T a, T b) { a - b; };

template<typename T>
concept Dividable = requires(T a, T b) { a/b; };

template<typename T>
concept DivAddable = Addable<T> && Dividable<T>;

template<typename T>
void f(T x)
{
    if constexpr(Addable<T>){ /*...*/ }
    else if constexpr(requires(T a, T b) { a + b; }){ /*...*/ }
}

template<typename T>
requires Addable<T>
auto f1(T a, T b) requires Subtractable<T>; // Addable<T> && Subtractable<T>

auto l = []<typename T> requires Addable<T>
    (T a, T b) requires Subtractable<T>{};

template<typename T>
requires Addable<T>
class C;

// infamous `requires requires`. First `requires` is requires-clause,
// second one is requires-expression. Useful if you don't want to introduce new
// concept.
template<typename T>
requires requires(T a, T b) {a + b;}
auto f4(T x);

template<typename T> /*...*/
concept xyz=requires (T x) // optional set of fictional parameter(s)
{
    // simple requirement: expression must be valid
    x++;    // expression must be valid
    
    // type requirement: `typename T`, T type must be a valid type
    typename T;
    typename T::value_type;

    // compound requirement: {expression}[noexcept][-> Concept];
    // {expression} -> Concept<A1, A2, ...> is equivalent to
    // requires Concept<decltype((expression)), A1, A2, ...>
    {*x};  // dereference must be valid
    {*x} noexcept;  // dereference must be noexcept
    // dereference must  return T::value_type
    {*x} noexcept -> std::same_as<typename T::value_type>;
    
    // nested requirement: requires ConceptName<...>;
    requires Addable<T>; // constraint Addable<T> must be satisfied
};

/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_sfinae_3.exe ./cpp/language_sfinae_3.cpp && (cd ../_build/cpp/;./language_sfinae_3.exe)
https://en.cppreference.com/w/cpp/language/sfinae
*/
template <int I> struct X { };
template <template <class T> class> struct Z { };
template <class T> void f(typename T::Y*){}
template <class T> void g(X<T::N>*){}
template <class T> void h(Z<T::template TT>*){}
struct A {};
struct B { int Y; };
struct C { typedef int N; };
struct D { typedef int TT; };
struct B1 { typedef int Y; };
struct C1 { static const int N = 0; };
struct D1 { 
    template <typename T>
    struct TT
    {    
    }; 
};
int main() {
    // Deduction fails in each of these cases:
    f<A>(0); // A does not contain a member Y
    f<B>(0); // The Y member of B is not a type
    g<C>(0); // The N member of C is not a non-type
    h<D>(0); // The TT member of D is not a template
    // Deduction succeeds in each of these cases:
    f<B1>(0); 
    g<C1>(0); 
    h<D1>(0);
}
// todo: needs to demonstrate overload resolution, not just failure


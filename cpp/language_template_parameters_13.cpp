/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_template_parameters_13.exe ./cpp/language_template_parameters_13.cpp && (cd ../_build/cpp/;./language_template_parameters_13.exe)
https://en.cppreference.com/w/cpp/language/template_parameters
*/
template<typename T> class X {}; // class template
struct A; // incomplete type
typedef struct {} B; // type alias to an unnamed type
int main()
{
    X<A> x1; // ok: 'A' names a type
    X<A*> x2; // ok: 'A*' names a type
    X<B> x3; // ok: 'B' names a type
}


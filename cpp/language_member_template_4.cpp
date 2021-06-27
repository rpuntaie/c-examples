/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_member_template_4.exe ./cpp/language_member_template_4.cpp && (cd ../_build/cpp/;./language_member_template_4.exe)
https://en.cppreference.com/w/cpp/language/member_template
*/
template<typename T>
struct A {
    void f(int); // non-template member
    template<typename T2>
    void f(T2); // member template
};
//template member definition
template<typename T>
template<typename T2>
void A<T>::f(T2)
{
    // some code
}
int main()
{
    A<char> ac;
    ac.f('c'); // calls template function A<char>::f<char>(char)
    ac.f(1);   // calls non-template function A<char>::f(int)
    ac.f<>(1); // calls template function A<char>::f<int>(int)
}


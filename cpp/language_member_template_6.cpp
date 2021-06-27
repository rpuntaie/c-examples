/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_member_template_6.exe ./cpp/language_member_template_6.cpp && (cd ../_build/cpp/;./language_member_template_6.exe)
https://en.cppreference.com/w/cpp/language/member_template
*/
struct A {
    template<typename T>
    operator T*(); // conversion to pointer to any type
};
// out-of-class definition
template<typename T>
A::operator T*() {return nullptr;}
// explicit specialization for char*
template<>
A::operator char*() {return nullptr;}
// explicit instantiation
template A::operator void*();
int main() {
    A a;
    int* ip = a.operator int*(); // explicit call to A::operator int*()
}


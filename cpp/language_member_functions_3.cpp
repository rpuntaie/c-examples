/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_member_functions_3.exe ./cpp/language_member_functions_3.cpp && (cd ../_build/cpp/;./language_member_functions_3.exe)
https://en.cppreference.com/w/cpp/language/member_functions
*/
#include <vector>
struct Array {
    std::vector<int> data;
    Array(int sz) : data(sz) {}
    // const member function
    int operator[](int idx) const {
                          // this has type const Array*
        return data[idx]; // transformed to (*this).data[idx];
    }
    // non-const member function
    int& operator[](int idx) {
                          // this has type Array*
        return data[idx]; // transformed to (*this).data[idx]
    }
};
int main()
{
    Array a(10);
    a[1] = 1; // OK: the type of a[1] is int&
    const Array ca(10);
    // ca[1] = 2; // Error: the type of ca[1] is int
}


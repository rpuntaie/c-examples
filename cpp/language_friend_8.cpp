/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_friend_8.exe ./cpp/language_friend_8.cpp && (cd ../_build/cpp/;./language_friend_8.exe)
https://en.cppreference.com/w/cpp/language/friend
*/
#include <iostream>
template<typename T>
class Foo {
 public:
    Foo(const T& val) : data(val) {}
 private:
    T data;
    // generates a non-template operator<< for this T
    friend std::ostream& operator<<(std::ostream& os, const Foo& obj)
    {
        return os << obj.data;
    }
};
int main()
{
    Foo<double> obj(1.23);
    std::cout << obj << '\n';
}


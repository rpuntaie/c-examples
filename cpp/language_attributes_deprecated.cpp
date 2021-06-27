/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_attributes_deprecated.exe ./cpp/language_attributes_deprecated.cpp && (cd ../_build/cpp/;./language_attributes_deprecated.exe)
https://en.cppreference.com/w/cpp/language/attributes/deprecated
*/
#include <iostream>
[[deprecated]]
void TriassicPeriod() {
    std::clog << "Triassic Period: [251.9 - 208.5] million years ago.\n";
}
[[deprecated("Use NeogenePeriod() instead.")]]
void JurassicPeriod() {
    std::clog << "Jurassic Period: [201.3 - 152.1] million years ago.\n";
}
[[deprecated("Use calcSomethingDifferently(int).")]]    
int calcSomething(int x) {
    return x * 2;
}
int main()
{
    TriassicPeriod();
    JurassicPeriod();
}


/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_attributes_deprecated.exe ./c/language_attributes_deprecated.c && (cd ../_build/c/;./language_attributes_deprecated.exe)
https://en.cppreference.com/w/c/language/attributes/deprecated
*/
#include <stdio.h>
[[deprecated]]
void TriassicPeriod(void)
{
    puts("Triassic Period: [251.9 - 208.5] million years ago.");
}
[[deprecated("Use NeogenePeriod() instead.")]]
void JurassicPeriod(void)
{
    puts("Jurassic Period: [201.3 - 152.1] million years ago.");
}
[[deprecated("Use calcSomethingDifferently(int).")]]    
int calcSomething(int x)
{
    return x * 2;
}
int main(void)
{
    TriassicPeriod();
    JurassicPeriod();
}


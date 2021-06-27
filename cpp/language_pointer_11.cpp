/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_pointer_11.exe ./cpp/language_pointer_11.cpp && (cd ../_build/cpp/;./language_pointer_11.exe)
https://en.cppreference.com/w/cpp/language/pointer
*/
template<typename T> T f(T n) { return n; }
double f(double n) { return n; }
int main()
{
    int (*p)(int) = f; // instantiates and selects f<int>
}


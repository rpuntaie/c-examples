/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_initializer_list.exe ./cpp/language_initializer_list.cpp && (cd ../_build/cpp/;./language_initializer_list.exe)
https://en.cppreference.com/w/cpp/language/initializer_list
*/
struct S {
    int n;
    S(int); // constructor declaration
    S() : n(7) {} // constructor definition.
                  // ": n(7)" is the initializer list
                  // ": n(7) {}" is the function body
};
S::S(int x) : n{x} {} // constructor definition. ": n{x}" is the initializer list
int main()
{
    S s; // calls S::S()
    S s2(10); // calls S::S(int)
}


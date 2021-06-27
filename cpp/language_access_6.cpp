/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_access_6.exe ./cpp/language_access_6.cpp && (cd ../_build/cpp/;./language_access_6.exe)
https://en.cppreference.com/w/cpp/language/access
*/
class S {
  public: // n, E, A, B, C, U, f are public members
    int n;
    enum E {A, B, C};
    struct U {};
    static void f() {}
};
int main() {
  S::f();     // S::f is accessible in main
  S s;
  s.n = S::B; // S::n and S::B are accessible in main
  S::U x;     // S::U is accessible in main
}


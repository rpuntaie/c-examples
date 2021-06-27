/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_noexcept_spec_5.exe ./cpp/language_noexcept_spec_5.cpp && (cd ../_build/cpp/;./language_noexcept_spec_5.exe) || true
https://en.cppreference.com/w/cpp/language/noexcept_spec
*/
// whether foo is declared noexcept depends on if the expression
// T() will throw any exceptions
template <class T>
  void foo() noexcept(noexcept(T())) {}
void bar() noexcept(true) {}
void baz() noexcept { throw 42; }  // noexcept is the same as noexcept(true)
int main() 
{
    foo<int>();  // noexcept(noexcept(int())) => noexcept(true), so this is fine
    bar();  // fine
    baz();  // compiles, but at runtime this calls std::terminate
}


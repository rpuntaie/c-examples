/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_override.exe ./cpp/language_override.cpp && (cd ../_build/cpp/;./language_override.exe)
https://en.cppreference.com/w/cpp/language/override
*/
struct A
{
    virtual void foo();
    void bar();
};
struct B : A
{
    //void foo() const override; // Error: B::foo does not override A::foo
                               // (signature mismatch)
    void foo() override; // OK: B::foo overrides A::foo
    //void bar() override; // Error: A::bar is not virtual
};
int main() {}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_reset.exe ./cpp/memory_shared_ptr_reset.cpp && (cd ../_build/cpp/;./memory_shared_ptr_reset.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/reset
*/
#include <memory>
#include <iostream>
struct Foo {
    Foo(int n = 0) noexcept : bar(n) {
        std::cout << "Foo: constructor, bar = " << bar << '\n';
    }
    ~Foo() {
         std::cout << "Foo: destructor, bar = " << bar << '\n';
    }
    int getBar() const noexcept { return bar; }
private:
    int bar;
};
int main()
{
    std::shared_ptr<Foo> sptr = std::make_shared<Foo>(1);
    std::cout << "The first Foo's bar is " << sptr->getBar() << "\n";
    // reset the shared_ptr, hand it a fresh instance of Foo
    // (the old instance will be destroyed after this call)
    sptr.reset(new Foo);
    std::cout << "The second Foo's bar is " << sptr->getBar() << "\n";
}


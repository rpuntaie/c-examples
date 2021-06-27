/*
g++ --std=c++20 -pthread -o ../_build/cpp/memory_shared_ptr_operator.exe ./cpp/memory_shared_ptr_operator.cpp && (cd ../_build/cpp/;./memory_shared_ptr_operator.exe)
https://en.cppreference.com/w/cpp/memory/shared_ptr/operator*
*/
#include <iostream>
#include <memory>
struct Foo
{
   Foo(int in) : a(in) {}
   void print() const
   {
      std::cout << "a = " << a << '\n';
   }
   int a;
};
int main()
{
   auto ptr = std::make_shared<Foo>(10);
   ptr->print();
   (*ptr).print();
}


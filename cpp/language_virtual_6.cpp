/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_virtual_6.exe ./cpp/language_virtual_6.cpp && (cd ../_build/cpp/;./language_virtual_6.exe)
https://en.cppreference.com/w/cpp/language/virtual
*/
class Base {
 public:
    virtual ~Base() { /* releases Base's resources */ }
};
class Derived : public Base {
    ~Derived() { /* releases Derived's resources */ }
};
int main()
{
    Base* b = new Derived;
    delete b; // Makes a virtual function call to Base::~Base()
              // since it is virtual, it calls Derived::~Derived() which can
              // release resources of the derived class, and then calls
              // Base::~Base() following the usual order of destruction
}


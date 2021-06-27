/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_virtual_1.exe ./cpp/language_virtual_1.cpp && (cd ../_build/cpp/;./language_virtual_1.exe) || true
https://en.cppreference.com/w/cpp/language/virtual
*/
class B {
    virtual void do_f(); // private member
 public:
    void f() { do_f(); } // public interface
};
struct D : public B {
    void do_f() override; // overrides B::do_f
};
int main()
{
    D d;
    B* bp = &d;
    bp->f(); // internally calls D::do_f();
}


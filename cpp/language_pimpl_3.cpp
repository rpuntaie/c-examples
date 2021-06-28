/*
# g++ --std=c++20 -pthread -o ../_build/cpp/language_pimpl_3.exe ./cpp/language_pimpl_3.cpp && (cd ../_build/cpp/;./language_pimpl_3.exe)
https://en.cppreference.com/w/cpp/language/pimpl
*/
#include <iostream>
#include <memory>
#include <experimental/propagate_const>
// interface (widget.h)
class widget {
    class impl;
    std::experimental::propagate_const<std::unique_ptr<impl>> pImpl;
 public:
    void draw() const; // public API that will be forwarded to the implementation
    void draw();
    bool shown() const { return true; } // public API that implementation has to call
    widget(int);
    ~widget(); // defined in the implementation file, where impl is a complete type
    widget(widget&&); // defined in the implementation file
                      // Note: calling draw() on moved-from object is UB
    widget(const widget&) = delete;
    widget& operator=(widget&&); // defined in the implementation file
    widget& operator=(const widget&) = delete;
};
// implementation (widget.cpp)
class widget::impl {
    int n; // private data
 public:
    void draw(const widget& w) const {
        if(w.shown()) // this call to public member function requires the back-reference 
            std::cout << "drawing a const widget " << n << '\n';
    }
    void draw(const widget& w) {
        if(w.shown())
            std::cout << "drawing a non-const widget " << n << '\n';
    }
    impl(int n) : n(n) {}
};
void widget::draw() const { pImpl->draw(*this); }
void widget::draw() { pImpl->draw(*this); }
widget::widget(int n) : pImpl{std::make_unique<impl>(n)} {}
widget::widget(widget&&) = default;
widget::~widget() = default;
widget& widget::operator=(widget&&) = default;
// user (main.cpp)
int main()
{
    widget w(7);
    const widget w2(8);
    w.draw();
    w2.draw();
}


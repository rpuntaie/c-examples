/*
g++ -std=c++20 -o ../_build/r/tt.o -c r/tt.cpp
*/

#include <type_traits>
#include <map>
#include <vector>
#include <string>

#ifdef __has_cpp_attribute  // check __has_cpp_attribute itself before using it
#   if __has_cpp_attribute(no_unique_address) >= 201803L
#       define CXX20_NO_UNIQUE_ADDR [[no_unique_address]]
#   endif
#endif
#ifndef CXX20_NO_UNIQUE_ADDR
#   define CXX20_NO_UNIQUE_ADDR
#endif

template<typename T>
class Widget{
    int x;
    CXX20_NO_UNIQUE_ADDR T obj;
};

struct TrickyObject{
    void operator delete(TrickyObject *ptr, std::destroying_delete_t){
        // without destroying_delete_t object would have been destroyed here
        const std::size_t realSize = 0;//ptr->GetRealSizeSomehow();
        // now we need to call the destructor by-hand
        ptr->~TrickyObject();
        // and free storage it occupies
        ::operator delete(ptr, realSize);
    }
    // ...
};


template<typename T>
struct S{
    explicit(!std::is_convertible_v<T, int>) S(T){}
};
void f(){
    S<char> sc = 'x';           // OK
    //S<std::string> ss1 = "x";   // Error, constructor is explicit
    S<std::string> ss2{"x"};    // OK
}


void f(int (&&)[]){};
void f(int (&)[1]){};
void g() {
  int arr[1];
  f(arr);       // calls `f(int (&)[1])`
  f({1, 2});    // calls `f(int (&&)[])`
  int(&r)[] = arr;
}

/*
clang -std=c++20 -c r/th.cpp || true
# g++ -std=c++20 -c r/th.cpp # https://www.mail-archive.com/gcc-bugs@gcc.gnu.org/msg681237.html
*/

#include <string>
#include <array>
#include <assert.h>

struct Base{
    constexpr virtual ~Base() = default;
    virtual int get() const = 0;    // non-constexpr
};

struct Derived1 : Base{
    constexpr int get() const override {
        return 1;
    }
};

struct Derived2 : Base{
    constexpr int get() const override {
        return 2;
    }
};

constexpr auto GetSum(){
    const Derived1 d1;
    const Derived2 d2;
    const Base* pb1 = &d1;
    const Base* pb2 = &d2;

    return pb1->get() + pb2->get();
}

static_assert(GetSum() == 1 + 2);   // evaluated at compile-time

constexpr void f(){
    try{
        auto p = new int;
        // ...
        delete p;
    }
    catch(...){     // ignored at compile-time
        // ...
    }
}


struct Base2{
    virtual ~Base2() = default;
    constexpr virtual int get() const = 0;
};

struct Derived22 : Base2{
    constexpr int get() const override {
        return 2;
    }
};

template<typename Base, typename Derived>
constexpr auto downcasted_get(){
    const Derived d;
    const Base& upcasted = d;
    const auto& downcasted = dynamic_cast<const Derived&>(upcasted);

    return downcasted.get();
}

static_assert(downcasted_get<Base, Derived1>() == 1);
static_assert(downcasted_get<Base2, Derived22>() == 2);

//// compile-time error, cannot cast Derived1 to Base2
//static_assert(downcasted_get<Base2, Derived1>() == 1);


union Foo {
  int i;
  float f;
};

constexpr int ff() {
  Foo foo{};
  foo.i = 3;    // i is an active member
  foo.f = 1.2f; // valid since C++20, f becomes an active member

//   return foo.i;  // error, reading inactive union member
  return foo.f;
}

//   // ### `constexpr` allocations
//   constexpr auto get_str()
//   {
//       std::string s1{"hello "};
//       std::string s2{"world"};
//       std::string s3 = s1 + s2;
//       return s3;
//   }
//   
//   constexpr auto get_array()
//   {
//       constexpr auto N = get_str().size();
//       std::array<char, N> arr{};
//       std::copy_n(get_str().data(), N, std::begin(arr));
//       return arr;
//   }
//   
//   static_assert(!get_str().empty());
//   
//   // error because it holds data allocated at compile-time
//   // constexpr auto str = get_str();
//   
//   // OK, string is stored in std::array<char>
//   constexpr auto result = get_array();

// ### Trivial default initialization in `constexpr` functions 
struct NonTrivial{
    bool b = false;
};

struct Trivial{
    bool b;
};

template <typename T>
constexpr T f1(const T& other) {
    T t;        // default initialization
    t = other;
    return t;
}

template <typename T>
constexpr auto f2(const T& other) {
    T t;
    return t.b;
}

void test(){
    constexpr auto a = f1(Trivial{});   // error in C++17, OK in C++20
    constexpr auto b = f1(NonTrivial{});// OK

    // constexpr auto c = f2(Trivial{}); // error, uninitialized Trivial::b is used
    constexpr auto d = f2(NonTrivial{}); // OK
}


// ### std::is_constant_evaluated()
constexpr int GetNumber(){
    if(std::is_constant_evaluated()){   // should not be `if constexpr`
        return 1;
    }
    return 2;
}

constexpr int GetNumber(int x){
    if(std::is_constant_evaluated()){   // should not be `if constexpr`
        return x;
    }
    return x+1;
}

void ice(){
    constexpr auto v1 = GetNumber();
    const auto v2 = GetNumber();

    // initialization of a non-const variable, not constant-evaluated
    auto v3 = GetNumber();

    assert(v1 == 1);
    assert(v2 == 1);
    assert(v3 == 2);

    constexpr auto v4 = GetNumber(1);
    int x = 1;

    // x is not a constant-expression, not constant-evaluated
    const auto v5 = GetNumber(x);

    assert(v4 == 1);
    assert(v5 == 2);    
}

// pathological examples
// always returns `true`
constexpr bool IsInConstexpr(int){
    if constexpr(std::is_constant_evaluated()){ // always `true`
        return true;
    }
    return false;
}

// always returns `sizeof(int)`
constexpr std::size_t GetArraySize(int){
    int arr[std::is_constant_evaluated()];  // always int arr[1];
    return sizeof(arr);
}

// always returns `1`
constexpr std::size_t GetStdArraySize(int){
    std::array<int, std::is_constant_evaluated()> arr;  // std::array<int, 1>
    return arr.size();
}

/*
g++ -std=c++20 -c r/tm.cpp
*/

#include <string>
#include <tuple>
#include <memory>
#include <vector>
#include <sstream>

struct S{
    int a: 1;
    int b: 1;
    int c;
};
static auto [A,B,C] = S{};
void f(){
    [[maybe_unused]] thread_local auto [a,b,c] = S{};
    auto l = [=](){
        return a + b + c;
    };

    auto m = [&](){
        // error, can't capture bit-fields 'a' and 'b' by-reference
        // return a + b + c;
        return c;
    };
}


struct X : private std::shared_ptr<int>{
    std::string payload;
};
// due to new rules, this function is used instead of std::shared_ptr<int>::get
template<int N>
std::string& get(X& x) {
    if constexpr(N==0) return x.payload;
}
namespace std {
    template<>
    class tuple_size<X> 
        : public std::integral_constant<int, 1>
    {};
    template<>
    class tuple_element<0, X> {
    public:
        using type = std::string;
    };
}
void g(){
    X x;
    auto& [payload] = x;
}


struct K {
    friend void foo();
private:
    int i;
};
void foo() {
    K a;
    auto x = a.i;   // OK
    auto [y] = a;   // Ill-formed until C++20, now OK
}


struct Obj{
    std::vector<int>& GetCollection();
};
Obj GetObj(){return Obj();}
// dangling reference, lifetime of Obj return by GetObj() is not extended
// for(auto x : GetObj().GetCollection()){
//    // ...
//}
void m(){
// OK
for(auto obj = GetObj(); auto item : obj.GetCollection()){
    // ...
}
// also can be used to maintain index
auto obj = GetObj();
auto collection = obj.GetCollection();
for(std::size_t i = 0 ; auto& v : collection) {++i;}
}



struct SS : std::stringstream {
  // ...
};
std::istream_iterator<char> begin(SS& x){
    return std::istream_iterator<char>(x);
}
std::istream_iterator<char> end(SS& x){
    return std::istream_iterator<char>();
}
void fx(){
    SS x;
    // X has member with name `end` inherited from std::stringstream
    // but due to new rules free begin()/end() are used
    for (auto&& i : x) {
        // ...
    }
}

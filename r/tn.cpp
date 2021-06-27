/*
g++ -std=c++20 -c r/tn.cpp
*/

int f(bool b){
    if(b) [[likely]] { // or [[unlikely]]
        return 12;
    }
    else{
        return 10;
    }
}


struct Empty{};
template<typename T>
struct Cpp17Widget{
    int i;
    T t;
};
template<typename T>
struct Cpp20Widget{
    int i;
    [[no_unique_address]] T t;
};


[[nodiscard("Don't leave me alone")]]
int get();
void nd(){
    get(); // warning: ignoring return value of function declared with 
           // 'nodiscard' attribute: Don't leave me alone
}


struct resource{
    // empty resource, no harm if discarded
    resource() = default;
    [[nodiscard("don't discard non-empty resource")]]
    resource(int fd);
};
void kd(){
    resource{};     // OK
    resource{1};    // warning
}


void HandleString(const char*){}
// distinct function name is required to handle UTF-8 in C++17
void HandleStringUTF8(const char*){}
// now it can be done using convenient overload
void HandleString(const char8_t*){}
void Cpp17(){
    HandleString("abc");        // char[4]
    //HandleStringUTF8(u8"abc");  // C++17: char[4] but UTF-8, 
                                // C++20: error, type is char8_t[4]
}
void Cpp20(){
    HandleString("abc");    // char
    HandleString(u8"abc");  // char8_t
}

//char32_t c{'\U00110000'};   // error: invalid universal character



/*
g++ -std=c++20 -o ../_build/r/tq.o -c r/tq.cpp
*/

#include <cstdio>

struct K {
    constexpr K(int) {}
    ~K(){}; // non-trivial
};
constinit K s1{42};  // OK
// constexpr K s2{42};  // error because destructor is not trivial
// tls_definitions.cpp
thread_local constinit int tls1{1};
thread_local int tls2{2};
// main.cpp
extern thread_local constinit int tls1;
extern thread_local int tls2;
int get_tls1() {
    return tls1;  // pure TLS access
}
int get_tls2() {
    return tls2;  // has implicit TLS initialization code
}


#define LOG1(...)                   \
    __VA_OPT__(std::printf(__VA_ARGS__);) \
    std::printf("\n");
#define LOG2(msg, ...) \
    std::printf("[" __FILE__ ":%d] " msg, __LINE__, __VA_ARGS__)
#define LOG3(msg, ...) \
    std::printf("[" __FILE__ ":%d] " msg, __LINE__ __VA_OPT__(,) __VA_ARGS__)
void x(){
LOG1();                      // std::printf("\n");
LOG1("number is %d", 12);    // std::printf("number is %d", 12); std::printf("\n");
// OK, std::printf("[" "file.cpp" ":%d] " "%d errors.\n", 14, 0);
LOG2("%d errors\n", 0);
// Error, std::printf("[" "file.cpp" ":%d] " "No errors\n", 17, );
// LOG2("No errors\n");
// OK, std::printf("[" "file.cpp" ":%d] " "No errors\n", 20);
LOG3("No errors\n");
}


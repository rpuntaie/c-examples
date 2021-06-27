/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_span_size_bytes.exe ./cpp/container_span_size_bytes.cpp && (cd ../_build/cpp/;./container_span_size_bytes.exe)
https://en.cppreference.com/w/cpp/container/span/size_bytes
*/
#include <span>
#include <cstdint>
int main()
{
    static constexpr std::int32_t a[] { 1, 2, 3, 4, 5 };
    constexpr std::span s{a};
    static_assert( sizeof(int32_t) == 4  );
    static_assert( std::size(a)    == 5  );
    static_assert( sizeof(a)       == 20 );
    static_assert( s.size()        == 5  );
    static_assert( s.size_bytes()  == 20 );
}


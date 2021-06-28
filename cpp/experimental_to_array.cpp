/*
# g++ --std=c++20 -pthread -o ../_build/cpp/experimental_to_array.exe ./cpp/experimental_to_array.cpp && (cd ../_build/cpp/;./experimental_to_array.exe)
https://en.cppreference.com/w/cpp/experimental/to_array
*/
#include <cstdlib>
#include <cassert>
#include <experimental/array>
#include <unistd.h>
// mkstemp(3) that works
template <std::size_t N>
int tempfd(char const (&tmpl)[N])
{
    auto s = std::experimental::to_array(tmpl);
    int fd = mkstemp(s.data());
    if (fd != -1)
        unlink(s.data());
    return fd;
}
int main()
{
    int fd = tempfd("/tmp/test.XXXXXX");
    int rt = close(fd);
    assert(rt == 0);
}


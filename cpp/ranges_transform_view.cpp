/*
g++ --std=c++20 -pthread -o ../_build/cpp/ranges_transform_view.exe ./cpp/ranges_transform_view.cpp && (cd ../_build/cpp/;./ranges_transform_view.exe)
https://en.cppreference.com/w/cpp/ranges/transform_view
*/
#include <algorithm>
#include <array>
#include <cstdio>
#include <ranges>
#include <string>
class Transcoder {
    static constexpr std::array r{
        0x02,-0x02,-0x42, 0x05, 0x04, 0x05, 0x04,-0x02,
        0x00,-0x0a, 0x06,-0x04, 0x00, 0x0c, 0x03,-0x06,
    };
    decltype(r.size()) p{}, q{};
public:
    char operator() (int x) {
        ! (p|q)
        ? (99 == x ? x += r[p++]  : x -= r[q++])
        : (0 < p && p < r.size()) ? x += r[p++]
        : (0 < q && q < r.size()) ? x -= r[q++]
        : (0)
        ;
        return x;
    }
};
int main()
{
    auto show = [](const char x) { std::putchar(x); };
    std::string in{ "cppreference.com\n" };
    std::ranges::for_each(in, show);
    std::string out;
    std::ranges::copy(
        std::ranges::views::transform(in, Transcoder{}),
        std::back_inserter(out));
    std::ranges::for_each(out, show);
    auto view = std::ranges::transform_view{ out, Transcoder{} };
    std::ranges::for_each(view, show);
    std::ranges::for_each(view, show);
}


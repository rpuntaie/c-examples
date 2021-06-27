/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_extreme_value_distribution.exe ./cpp/numeric_random_extreme_value_distribution.cpp && (cd ../_build/cpp/;./numeric_random_extreme_value_distribution.exe)
https://en.cppreference.com/w/cpp/numeric/random/extreme_value_distribution
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <vector>
template<int Height = 5, int BarWidth = 1, int Padding = 1, int Offset = 0,
         bool MinMax = true, class S>
void draw_vbars(S const& s)
{
    static_assert((Height > 0) && (BarWidth > 0) && (Padding >= 0) && (Offset >= 0));
    const auto repeat_cout = [](auto const& v, int n)
    {
        while (n-- > 0)
            std::cout << v;
    };
    const auto [min, max] = std::minmax_element(std::cbegin(s), std::cend(s));
    std::vector<std::div_t> qr;
    for (float e : s) {
        qr.push_back(std::div(std::lerp(0.f, Height * 8 , (e - *min) / (*max - *min)), 8));
    }
    for (auto h{Height}; h-- > 0 ;) {
        repeat_cout(' ', Offset);
        for (auto [q, r] : qr) {
            char d[] = "█"; // == { 0xe2, 0x96, 0x88, 0 }
            if (q < h) {
                repeat_cout(' ', BarWidth);
            } else {
                if (q == h) {
                    d[2] -= (7 - r);
                }
                repeat_cout(d, BarWidth);
            }
            repeat_cout(' ', Padding);
        }
        if (MinMax && Height > 1) {
            if (h == Height - 1)
                std::cout << "┬ " << *max;
            else if (h == 0)
                std::cout << "┴ " << *min;
            else
                std::cout << "│";
        }
        std::cout << '\n';
    }
}
int main()
{
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::extreme_value_distribution<> d{-1.618f, 1.618f};
    const int norm = 10'000;
    const float cutoff = 0.000'3f;
    std::map<int, int> hist{};
    for(int n=0; n<norm; ++n) {
        ++hist[std::round(d(gen))];
    }
    std::vector<float> bars;
    std::vector<int> indices;
    for(const auto [n,p] : hist) {
        float x = p*(1.0f/norm);
        if (x > cutoff) {
            bars.push_back(x);
            indices.push_back(n);
        }
    }
    draw_vbars<8,4>(bars);
    for (int n : indices) {
        std::cout << " " << std::setw(2) << n << "  ";
    }
    std::cout << '\n';
}


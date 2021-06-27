/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_cauchy_distribution.exe ./cpp/numeric_random_cauchy_distribution.cpp && (cd ../_build/cpp/;./numeric_random_cauchy_distribution.exe)
https://en.cppreference.com/w/cpp/numeric/random/cauchy_distribution
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <vector>
template <int Height = 5, int BarWidth = 1, int Padding = 1, int Offset = 0,
          bool DrawMinMax = true, class Sample>
void draw_vbars(Sample const& s) {
    static_assert((Height > 0) && (BarWidth > 0) && (Padding >= 0) && (Offset >= 0));
    auto cout_n = [](auto const& v, int n) { while (n-- > 0) std::cout << v; };
    const auto [min, max] = std::minmax_element(std::cbegin(s), std::cend(s));
    std::vector<std::div_t> qr;
    for (float e : s) {
        qr.push_back(std::div(std::lerp(0.f, Height*8, (e - *min)/(*max - *min)), 8));
    }
    for (auto h{Height}; h-- > 0 ;) {
        cout_n(' ', Offset);
        for (auto [q, r] : qr) {
            char d[] = "█"; // == { 0xe2, 0x96, 0x88, 0 }
            q < h ? d[0] = ' ', d[1] = '\0' : q == h ? d[2] -= (7 - r) : 0;
            cout_n(d, BarWidth);
            cout_n(' ', Padding);
        }
        if (DrawMinMax && Height > 1)
            h == Height - 1 ? std::cout << "┬ " << *max:
                     h != 0 ? std::cout << "│"
                            : std::cout << "┴ " << *min;
        cout_n('\n', 1);
    }
}
int main() {
    std::random_device rd{};
    std::mt19937 gen{rd()};
    auto cauchy = [&gen](const float x₀, const float 𝛾) {
        std::cauchy_distribution<float> d{ x₀ /* a */, 𝛾 /* b */};
        const int norm = 1'00'00;
        const float cutoff = 0.005f;
        std::map<int, int> hist{};
        for (int n=0; n!=norm; ++n) { ++hist[std::round(d(gen))]; }
        std::vector<float> bars;
        std::vector<int> indices;
        for (const auto [n, p] : hist) {
            if (float x = p * (1.0/norm); cutoff < x) {
                bars.push_back(x);
                indices.push_back(n);
            }
        }
        std::cout << "x₀ = " << x₀ << ", 𝛾 = " << 𝛾 << ":\n";
        draw_vbars<4,3>(bars);
        for (int n : indices) { std::cout << "" << std::setw(2) << n << "  "; }
        std::cout << "\n\n";
    };
    cauchy(/* x₀ = */ -2.0f, /* 𝛾 = */ 0.50f);
    cauchy(/* x₀ = */ +0.0f, /* 𝛾 = */ 1.25f);
}


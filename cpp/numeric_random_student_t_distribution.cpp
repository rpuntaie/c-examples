/*
g++ --std=c++20 -pthread -o ../_build/cpp/numeric_random_student_t_distribution.exe ./cpp/numeric_random_student_t_distribution.cpp && (cd ../_build/cpp/;./numeric_random_student_t_distribution.exe)
https://en.cppreference.com/w/cpp/numeric/random/student_t_distribution
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
    auto cout_n = [](auto const& v, int n) { while (n-- > 0) { std::cout << v; } };
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
    std::student_t_distribution<> d{10.0f};
    const int norm = 10'000;
    const float cutoff = 0.000'3f;
    std::map<int, int> hist{};
    for(int n=0; n<norm; ++n) { ++hist[std::round(d(gen))]; }
    std::vector<float> bars;
    std::vector<int> indices;
    for (const auto [n, p] : hist) {
        if (float x = p * (1.0f / norm); cutoff < x) {
            bars.push_back(x);
            indices.push_back(n);
        }
    }
    draw_vbars<8,5>(bars);
    for (int n : indices) { std::cout << " " << std::setw(2) << n << "   "; }
    std::cout << '\n';
}


/*
g++ -std=c++20 -o ../_build/r/ch.exe r/ch.cpp && (cd ../_build/r;./ch.exe)
*/

#include <iostream>
#include <iomanip>
#include <ranges>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
 

void r1() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    auto results = numbers | std::views::filter([](int n){ return n % 2 == 0; })
                           | std::views::transform([](int n){ return n * 2; });
    for (auto v: results) std::cout << v << " ";     // 4 8 12
}

// https://mariusbancila.ro/blog/2019/01/20/cpp-code-samples-before-and-after-ranges/

std::string to_roman(int value)
{
   std::vector<std::pair<int, char const*>> roman
   {
      { 1000, "M" },{ 900, "CM" },
      { 500, "D" },{ 400, "CD" },
      { 100, "C" },{ 90, "XC" },
      { 50, "L" },{ 40, "XL" },
      { 10, "X" },{ 9, "IX" },
      { 5, "V" },{ 4, "IV" },
      { 1, "I" }
   };
   std::string result;
   for (auto const & [d, r]: roman)
   {
      while (value >= d)
      {
         result += r;
         value -= d;
      }
   }
   return result;
}
std::vector<int> v{1,1,2,3,5,8,13,21,34};
auto print_elem = [](auto const e) {std::cout << e << '\n'; };
auto is_even = [](auto const i) {return i % 2 == 0; };

namespace rv = std::views;
namespace rs = std::ranges;

void r2(){
  rs::for_each(std::as_const(v), print_elem);
  for (auto const i : v | rv::reverse) print_elem(i);
  for (auto const i : v | rv::reverse | rv::filter(is_even)) print_elem(i);
  for (auto const i : v | rv::drop(2) | rv::take(3) | rv::filter(is_even)) print_elem(i);
  for (auto n : rs::iota_view(101, 201)) print_elem(n);
  rs::for_each(rv::iota(101, 201), print_elem, to_roman);
}


int r3()
{
    auto words = std::istringstream{"today is yesterday’s tomorrow"};
    for (const auto& s: std::ranges::istream_view<std::string>(words)) {
        std::cout << std::quoted(s, '/') << ' ';
    }
    std::cout << '\n';
 
    auto floats = std::istringstream{"1.1  2.2\t3.3\v4.4\f55\n66\r7.7  8.8"};
    std::ranges::copy(
        std::ranges::istream_view<float>(floats),
        std::ostream_iterator<float>{std::cout, ", "});
    std::cout << '\n';
}


int main() {
  r1();
  r2();
  r3();

for (auto n : rs::iota_view(101, 201) 
            | rv::reverse
            | rv::filter([](auto v) {
                return v % 7 == 0; })
            | rv::transform(to_roman)
            | rv::take(3))
   print_elem(n);

auto v = rs::iota_view(101, 201)
       | rv::reverse
       | rv::filter([](auto v) {return v % 7 == 0; })
       | rv::transform(to_roman)
       | rv::take(3);

}

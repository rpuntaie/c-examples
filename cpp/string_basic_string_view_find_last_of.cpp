/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_find_last_of.exe ./cpp/string_basic_string_view_find_last_of.cpp && (cd ../_build/cpp/;./string_basic_string_view_find_last_of.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/find_last_of
*/
#include <string_view>
#include <iostream>
int main()
{
  using namespace std::literals;
  constexpr auto N = std::string_view::npos;
  static_assert(
    5 == "delete"sv.find_last_of("cdef"sv) &&
      //       └────────────────────┘
    N == "double"sv.find_last_of("fghi"sv) &&
      //
    0 == "else"sv.find_last_of("bcde"sv, 2 /* pos [0..2]: "els" */) &&
      //  └────────────────────────┘
    N == "explicit"sv.find_last_of("abcd"sv, 4 /* pos [0..4]: "expli" */) &&
      //
    3 == "extern"sv.find_last_of('e') &&
      //     └────────────────────┘
    N == "false"sv.find_last_of('x') &&
      //
    0 == "inline"sv.find_last_of('i', 2 /* pos [0..2]: "inl" */) &&
      //  └───────────────────────┘
    N == "mutable"sv.find_last_of('a', 2 /* pos [0..2]: "mut" */) &&
      //
    3 == "namespace"sv.find_last_of("cdef", 3 /* pos [0..3]: "name" */, 3 /* "cde" */) &&
      //     └─────────────────────────┘
    N == "namespace"sv.find_last_of("cdef", 3 /* pos [0..3]: "name" */, 2 /* "cd" */)
  );
  std::cout << "All tests passed.\n";
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_optional_hash.exe ./cpp/utility_optional_hash.cpp && (cd ../_build/cpp/;./utility_optional_hash.exe)
https://en.cppreference.com/w/cpp/utility/optional/hash
*/
#include <optional>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std::literals;
int main()
{
    using OptStr = std::optional<std::string>;
    // hash<optional> makes it possible to use unordered_set
    std::unordered_set<OptStr> s = {
        "ABC"s, "abc"s, std::nullopt, "def"s
    };
    for(const auto& o : s) {
        std::cout << o.value_or("(null)") << '\t' << std::hash<OptStr>{}(o) << '\n';
    }
}


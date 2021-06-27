/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_find.exe ./cpp/container_unordered_map_find.cpp && (cd ../_build/cpp/;./container_unordered_map_find.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/find
*/
#include <cstddef>
#include <iostream>
#include <functional>
#include <string>
#include <string_view>
#include <unordered_map>
using namespace std::literals;
using std::size_t;
struct string_hash
{
    using hash_type = std::hash<std::string_view>;
    using is_transparent = void;
    size_t operator()(const char* str) const        { return hash_type{}(str); }
    size_t operator()(std::string_view str) const   { return hash_type{}(str); }
    size_t operator()(std::string const& str) const { return hash_type{}(str); }
};
int main()
{
    // simple comparison demo
    std::unordered_map<int,char> example = {{1,'a'},{2,'b'}};
    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
    } else {
        std::cout << "Not found\n";
    }
    // C++20 demo: Heterogeneous lookup for unordered containers (transparent hashing)
    std::unordered_map<std::string, size_t, string_hash, std::equal_to<>> map{ {"one"s, 1} };
    std::cout << std::boolalpha
        << (map.find("one")   != map.end()) << '\n'
        << (map.find("one"s)  != map.end()) << '\n'
        << (map.find("one"sv) != map.end()) << '\n';
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/algorithm_search.exe ./cpp/algorithm_search.cpp && (cd ../_build/cpp/;./algorithm_search.exe)
https://en.cppreference.com/w/cpp/algorithm/search
*/
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
template <typename Container>
bool in_quote(const Container& cont, const std::string& s)
{
    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}
int main()
{
    std::string str = "why waste time learning, when ignorance is instantaneous?";
    // str.find() can be used as well
    std::cout << std::boolalpha << in_quote(str, "learning") << '\n'
                                << in_quote(str, "lemming")  << '\n';
    std::vector<char> vec(str.begin(), str.end());
    std::cout << std::boolalpha << in_quote(vec, "learning") << '\n'
                                << in_quote(vec, "lemming")  << '\n';
    // The C++17 overload demo:
    std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
                     " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    std::string needle = "pisci";
    auto it = std::search(in.begin(), in.end(),
                   std::boyer_moore_searcher(
                      needle.begin(), needle.end()));
    if(it != in.end())
        std::cout << "The string " << needle << " found at offset "
                  << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}


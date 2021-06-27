/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_unordered_map_operator_at.exe ./cpp/container_unordered_map_operator_at.cpp && (cd ../_build/cpp/;./container_unordered_map_operator_at.exe)
https://en.cppreference.com/w/cpp/container/unordered_map/operator_at
*/
#include <iostream>
#include <string>
#include <unordered_map>
int main()
{
    std::unordered_map<char, int> letter_counts {{'a', 27}, {'b', 3}, {'c', 1}};
    std::cout << "initially:\n";
    for (const auto &pair : letter_counts) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    letter_counts['b'] = 42;  // update an existing value
    letter_counts['x'] = 9;  // insert a new value
    std::cout << "after modifications:\n";
    for (const auto &pair : letter_counts) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    // count the number of occurrences of each word
    // (the first call to operator[] initialized the counter with zero)
    std::unordered_map<std::string, size_t>  word_map;
    for (const auto &w : { "this", "sentence", "is", "not", "a", "sentence",
                           "this", "sentence", "is", "a", "hoax"}) {
        ++word_map[w];
    }
    for (const auto &[word, count] : word_map) {
        std::cout << count << " occurrences of word '" << word << "'\n";
    }
}


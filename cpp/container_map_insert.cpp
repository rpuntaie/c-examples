/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_map_insert.exe ./cpp/container_map_insert.cpp && (cd ../_build/cpp/;./container_map_insert.exe)
https://en.cppreference.com/w/cpp/container/map/insert
*/
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std::literals;
template<typename It>
void printInsertionStatus(It it, bool success)
{
    std::cout << "Insertion of " << it->first << (success ? " succeeded\n" : " failed\n");
}
int main()
{
    std::map<std::string, float> karasunoPlayerHeights;
    // Overload 3: insert from rvalue reference
    const auto [it_hinata, success] = karasunoPlayerHeights.insert({"Hinata"s, 162.8});
    printInsertionStatus(it_hinata, success);
    {
        // Overload 1: insert from lvalue reference
        const auto [it, success2] = karasunoPlayerHeights.insert(*it_hinata);
        printInsertionStatus(it, success2);
    }
    {
        // Overload 2: insert via forwarding to emplace
        const auto [it, success] = karasunoPlayerHeights.insert({"Kageyama", 180.6});
        printInsertionStatus(it, success);
    }
    {
        // Overload 6: insert from rvalue reference with positional hint
        const std::size_t n = std::size(karasunoPlayerHeights);
        const auto it = karasunoPlayerHeights.insert(it_hinata, {"Azumane"s, 184.7});
        printInsertionStatus(it, std::size(karasunoPlayerHeights) != n);
    }
    {
        // Overload 4: insert from lvalue reference with positional hint
        const std::size_t n = std::size(karasunoPlayerHeights);
        const auto it = karasunoPlayerHeights.insert(it_hinata, *it_hinata);
        printInsertionStatus(it, std::size(karasunoPlayerHeights) != n);
    }
    {
        // Overload 5: insert via forwarding to emplace with positional hint
        const std::size_t n = std::size(karasunoPlayerHeights);
        const auto it = karasunoPlayerHeights.insert(it_hinata, {"Tsukishima", 188.3});
        printInsertionStatus(it, std::size(karasunoPlayerHeights) != n);
    }
    auto node_hinata = karasunoPlayerHeights.extract(it_hinata);
    std::map<std::string, float> playerHeights;
    // Overload 7: insert from iterator range
    playerHeights.insert(std::begin(karasunoPlayerHeights), std::end(karasunoPlayerHeights));
    // Overload 8: insert from initializer_list
    playerHeights.insert({{"Kozume"s, 169.2}, {"Kuroo", 187.7}});
    // Overload 9: insert node
    const auto status = playerHeights.insert(std::move(node_hinata));
    printInsertionStatus(status.position, status.inserted);
    node_hinata = playerHeights.extract(status.position);
    {
        // Overload 10: insert node with positional hint
        const std::size_t n = std::size(playerHeights);
        const auto it = playerHeights.insert(std::begin(playerHeights), std::move(node_hinata));
        printInsertionStatus(it, std::size(playerHeights) != n);
    }
    // Print resulting map
    std::cout << std::left << '\n';
    for (const auto& [name, height] : playerHeights)
        std::cout << std::setw(10) << name << " | " << height << "cm\n";
}


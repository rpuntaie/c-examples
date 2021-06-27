/*
g++ --std=c++20 -pthread -o ../_build/cpp/container_map_find.exe ./cpp/container_map_find.cpp && (cd ../_build/cpp/;./container_map_find.exe)
https://en.cppreference.com/w/cpp/container/map/find
*/
#include <iostream>
#include <map>
struct FatKey   { int x; int data[1000]; };
struct LightKey { int x; };
// Note: as detailed above, the container must use std::less<> (or other 
//   transparent Comparator) to access these overloads.
// This includes standard overloads, such as between std::string and std::string_view.
bool operator<(const FatKey& fk, const LightKey& lk) { return fk.x < lk.x; }
bool operator<(const LightKey& lk, const FatKey& fk) { return lk.x < fk.x; }
bool operator<(const FatKey& fk1, const FatKey& fk2) { return fk1.x < fk2.x; }
int main()
{  
// simple comparison demo
    std::map<int,char> example = {{1,'a'},{2,'b'}};
    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
    } else {
        std::cout << "Not found\n";
    }
// transparent comparison demo
    std::map<FatKey, char, std::less<>> example2 = { { {1, {} },'a'}, { {2, {} },'b'} };
    LightKey lk = {2};
    auto search2 = example2.find(lk);
    if (search2 != example2.end()) {
        std::cout << "Found " << search2->first.x << " " << search2->second << '\n';
    } else {
        std::cout << "Not found\n";
    }
// Obtaining const iterators.
// Compiler decides whether to return iterator of (non) const type by way of accessing
// map; to prevent modification on purpose, one of easiest choices is to access map by
// const reference.
    const auto& example2ref = example2;
    auto search3 = example2ref.find(lk);
    if (search3 != example2.end()) {
        std::cout << "Found " << search3->first.x << ' ' << search3->second << '\n';
    //  search3->second = 'c'; // error: assignment of member
                               // 'std::pair<const FatKey, char>::second'
                               // in read-only object
    }
}


/*
g++ -std=c++20 -o ../_build/r/b2.exe r/b2.cpp && (cd ../_build/r;./b2.exe)
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
  
// Driver Code
int main()
{
    // Key-value pair declared inside
    // Map data structure
    map<string, string> fav_lang{
        { "John", "Java" },
        { "Alex", "C++" },
        { "Peter", "Python" }
    };
    // Structure binding concept used
    // position and success are used
    // in place of first and second
    auto[process, success]
        = fav_lang.insert({ "Henry",
                            "Golang" });
    // Check boolean value of success
    if (success) {
        cout << "Insertion done!!"
             << endl;
    }
    // Iterate over map
    for (const auto & [ name, lang ] : fav_lang) {
  
        cout << name << ":"
             << lang << endl;
    }
    return 0;
}

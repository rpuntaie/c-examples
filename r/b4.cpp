/*
g++ -std=c++20 -o ../_build/r/b4.exe r/b4.cpp && (cd ../_build/r;./b4.exe)
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Helper function to print content
// of string vector
void print(const string& str,
           const vector<string>& vec)
{
    cout << str;
    for (const auto& i : vec) {
        cout << i << " ";
    }
    cout << endl;
}
// Driver Code
int main()
{
    // Declare vector of string
    vector<string> vec{ "abc","xyz","def","ghi" };
    // Invoke print helper function
    print("Initial vector: ", vec);
    // abc -> $$$, and the scope of "it"
    // Function invoked for passing
    // iterators from begin to end
    if (const auto it = find(begin(vec),
                             end(vec), "abc");
        // Check if the iterator reaches
        // to the end or not
        it != end(vec)) {
        // Replace the string if an
        // iterator doesn't reach end
        *it = "$$$";
    }
    // def -> ###
    // Replace another string using
    // the same iterator name
    if (const auto it = find(begin(vec),end(vec),"def");
        it != end(vec)) {
        *it = "###";
    }
    print("Final vector: ", vec);
    return 0;
}

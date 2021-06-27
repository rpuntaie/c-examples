/*
g++ --std=c++20 -pthread -o ../_build/cpp/language_direct_initialization.exe ./cpp/language_direct_initialization.cpp && (cd ../_build/cpp/;./language_direct_initialization.exe)
https://en.cppreference.com/w/cpp/language/direct_initialization
*/
#include <iterator>
#include <string>
#include <fstream>
int main()
{
    std::ifstream file("data.txt");
    // the following is a function declaration:
    std::string str(std::istreambuf_iterator<char>(file),
                    std::istreambuf_iterator<char>());
    // it declares a function called str, whose return type is std::string,
    // first parameter has type std::istreambuf_iterator<char> and the name "file"
    // second parameter has no name and has type std::istreambuf_iterator<char>(),
    // which is rewritten to function pointer type std::istreambuf_iterator<char>(*)()
    // pre-c++11 fix: extra parentheses around one of the arguments
    std::string str( (std::istreambuf_iterator<char>(file) ),
                      std::istreambuf_iterator<char>());  
    // post-C++11 fix: list-initialization for any of the arguments
    std::string str(std::istreambuf_iterator<char>{file}, {});
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_view_empty.exe ./cpp/string_basic_string_view_empty.cpp && (cd ../_build/cpp/;./string_basic_string_view_empty.exe)
https://en.cppreference.com/w/cpp/string/basic_string_view/empty
*/
#include <string_view>
#include <iostream>
void check_string(std::string_view ref)
{
        // Print a string surrounded by single quotes, its length
        // and whether it is considered empty.
        std::cout << std::boolalpha
                  << "'" << ref << "' has " << ref.size()
                  << " character(s); emptiness: " << ref.empty() << '\n';
}
int main(int argc, char **argv)
{
        // An empty string
        check_string("");
        // Almost always not empty: argv[0]
        if (argc > 0)
                check_string(argv[0]);
}


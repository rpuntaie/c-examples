/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_basic_string_resize.exe ./cpp/string_basic_string_resize.cpp && (cd ../_build/cpp/;./string_basic_string_resize.exe)
https://en.cppreference.com/w/cpp/string/basic_string/resize
*/
#include <iostream>
#include <stdexcept>
int main()
{
    std::cout << "Basic functionality:\n";
    const unsigned  desired_length(8);
    std::string     long_string( "Where is the end?" );
    std::string     short_string( "Ha" );
    // Shorten
    std::cout << "Before: \"" << long_string << "\"\n";
    long_string.resize( desired_length );
    std::cout << "After: \"" << long_string <<  "\"\n";
    // Lengthen
    std::cout << "Before: \"" << short_string <<  "\"\n";
    short_string.resize( desired_length, 'a' );
    std::cout << "After: \"" << short_string <<  "\"\n";
    std::cout  << "\nErrors:\n";
    {
        std::string s;    
        try {
            // size is OK, no length_error
            // (may throw bad_alloc)
            s.resize(s.max_size() - 1, 'x');
        } catch (const std::bad_alloc&) {
            std::cout << "1. bad alloc\n";
        }
        try {
            // size is OK, no length_error
            // (may throw bad_alloc)
            s.resize(s.max_size(), 'x');
        } catch (const std::bad_alloc& exc) {
            std::cout << "2. bad alloc\n";
        }
        try {
            // size is BAD, throw length_error
            s.resize(s.max_size() + 1, 'x');
        } catch (const std::length_error&) {
            std::cout << "3. length error\n";
        }
     }
}


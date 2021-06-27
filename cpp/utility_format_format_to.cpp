/*
g++ --std=c++20 -pthread -o ../_build/cpp/utility_format_format_to.exe ./cpp/utility_format_format_to.cpp && (cd ../_build/cpp/;./utility_format_format_to.exe)
https://en.cppreference.com/w/cpp/utility/format/format_to
*/
#include <format>
#include <iostream>
#include <iterator>
#include <string>
auto main() -> int
{
    std::string buffer;
    std::format_to(
        std::back_inserter(buffer), //< OutputIt
        "Hello, C++{}!\n",          //< fmt 
        "20");                      //< arg
    std::cout << buffer;
    buffer.clear();
    std::format_to(
        std::back_inserter(buffer), //< OutputIt
        "Hello, {0}::{1}!{2}",      //< fmt 
        "std",                      //< arg {0}
        "format_to()",              //< arg {1}
        "\n",                       //< arg {2}
        "extra param(s)...");       //< unused
    std::cout << buffer;
    std::wstring wbuffer;
    std::format_to(
        std::back_inserter(wbuffer),//< OutputIt 
        L"Hello, {2}::{1}!{0}",     //< fmt
        L"\n",                      //< arg {0}
        L"format_to()",             //< arg {1}
        L"std",                     //< arg {2}
        L"...is not..."             //< unused
        L"...an error!");           //< unused
    std::wcout << wbuffer;
}


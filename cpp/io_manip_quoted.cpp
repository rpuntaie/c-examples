/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_quoted.exe ./cpp/io_manip_quoted.cpp && (cd ../_build/cpp/;./io_manip_quoted.exe)
https://en.cppreference.com/w/cpp/io/manip/quoted
*/
#include <iostream>
#include <iomanip>
#include <sstream>
int main()
{
    std::stringstream ss;
    std::string in = "String with spaces, and embedded \"quotes\" too";
    std::string out;
    auto show = [&](const auto& what) {
        &what == &in
            ?   std::cout << "read in     [" << in << "]\n"
                          << "stored as   [" << ss.str() << "]\n"
            :   std::cout << "written out [" << out << "]\n\n";
    };
    ss << quoted(in); // uses ADL, so `std::` can be omitted
    show(in);
    ss >> quoted(out);
    show(out);
    ss.str(""); // clear the stream buffer
    in = "String with spaces, and embedded $quotes$ too";
    const char delim {'$'};
    const char escape {'%'};
    ss << std::quoted(in, delim, escape);
    show(in);
    ss >> std::quoted(out, delim, escape);
    show(out);
}


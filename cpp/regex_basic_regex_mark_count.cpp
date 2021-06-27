/*
g++ --std=c++20 -pthread -o ../_build/cpp/regex_basic_regex_mark_count.exe ./cpp/regex_basic_regex_mark_count.cpp && (cd ../_build/cpp/;./regex_basic_regex_mark_count.exe)
https://en.cppreference.com/w/cpp/regex/basic_regex/mark_count
*/
#include <iostream>
#include <regex>
int main()
{    
    std::regex r1{"abcde"};
    std::cout << "r1 has " << r1.mark_count() << " subexpressions" <<  '\n';
    //  Expected: 0
    std::regex r2{"ab(c)de"};
    std::cout << "r2 has " << r2.mark_count() << " subexpressions" << '\n';
    //  Expected: 1
    std::regex r3{"a(bc)d(e)"}; 
    std::cout << "r3 has " << r3.mark_count() << " subexpressions" << '\n';
    //  Expected: 2
    //  nested sub-expressions
    std::regex r4{"abc(de(fg))"};
    std::cout << "r4 has " << r4.mark_count() << " subexpressions" << '\n';
    //  Expected: 2
    //  escaped parentheses
    std::regex r5{"a(bc\\(\\)de)"};
    std::cout << "r5 has " << r5.mark_count() << " subexpressions" << '\n';
    //  Expected: 1
    //  using nosubs flag
    std::regex r6 {"ab(c)de", std::regex_constants::nosubs};
    std::cout << "r6 has " << r6.mark_count() << " subexpressions" << '\n';
    //  Expected: 0
}


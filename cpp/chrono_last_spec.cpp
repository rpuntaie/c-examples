/*
g++ --std=c++20 -pthread -o ../_build/cpp/chrono_last_spec.exe ./cpp/chrono_last_spec.cpp && (cd ../_build/cpp/;./chrono_last_spec.exe)
https://en.cppreference.com/w/cpp/chrono/last_spec
*/
#include <iostream>
#include <chrono>
int main()
{
    std::cout << std::boolalpha;
    constexpr auto mdl {std::chrono::June/std::chrono::last};
    std::cout << (mdl == std::chrono::month_day_last(std::chrono::month(6))) << ' ';
    constexpr auto ymwdl {std::chrono::year(2023)/
                          std::chrono::December/
                          std::chrono::Tuesday[std::chrono::last]
                         };
    std::cout << (ymwdl == std::chrono::year_month_weekday_last(
                           std::chrono::year(2023), 
                           std::chrono::month(12),
                           std::chrono::weekday_last(std::chrono::Tuesday))
                           ) << '\n';
}


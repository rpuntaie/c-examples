/*
g++ --std=c++20 -pthread -o ../_build/cpp/io_manip_put_money.exe ./cpp/io_manip_put_money.cpp && (cd ../_build/cpp/;./io_manip_put_money.exe) || true
https://en.cppreference.com/w/cpp/io/manip/put_money
*/
#include <iostream>
#include <iomanip>
int main()
{
    long double mon = 123.45; // or std::string mon = "123.45";
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << std::showbase
              << "en_US: " << std::put_money(mon)
              << " or " << std::put_money(mon, true) << '\n';
    std::cout.imbue(std::locale("ru_RU.UTF-8"));
    std::cout << "ru_RU: " << std::put_money(mon)
              << " or " << std::put_money(mon, true) << '\n';
    std::cout.imbue(std::locale("ja_JP.UTF-8"));
    std::cout << "ja_JP: " << std::put_money(mon)
              << " or " << std::put_money(mon, true) << '\n';
}


/*
g++ --std=c++20 -pthread -o ../_build/cpp/string_wide_wcschr.exe ./cpp/string_wide_wcschr.cpp && (cd ../_build/cpp/;./string_wide_wcschr.exe)
https://en.cppreference.com/w/cpp/string/wide/wcschr
*/
#include <iostream>
#include <cwchar>
#include <locale>
int main()
{
    const wchar_t arr[] = L"白猫 黒猫 кошки";
    const wchar_t* cat = std::wcschr(arr, L'猫');
    const wchar_t* dog = std::wcschr(arr, L'犬');
    std::cout.imbue(std::locale("en_US.utf8"));
    if(cat)
        std::cout << "The character 猫 found at position " << cat - arr << '\n';
    else
        std::cout << "The character 猫 not found\n";
    if(dog)
        std::cout << "The character 犬 found at position " << dog - arr << '\n';
    else
        std::cout << "The character 犬 not found\n";
}


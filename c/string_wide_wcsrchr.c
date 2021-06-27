/*
gcc -std=c99 -pthread -o ../_build/c/string_wide_wcsrchr.exe ./c/string_wide_wcsrchr.c && (cd ../_build/c/;./string_wide_wcsrchr.exe)
https://en.cppreference.com/w/c/string/wide/wcsrchr
*/
#include <wchar.h>
#include <stdio.h>
#include <locale.h>
int main(void)
{
    wchar_t arr[] = L"白猫 黒猫 кошки";
    wchar_t *cat = wcsrchr(arr, L'猫');
    wchar_t *dog = wcsrchr(arr, L'犬');
    setlocale(LC_ALL, "en_US.utf8");
    if(cat)
        printf("The character 猫 found at position %td\n", cat-arr);
    else
        puts("The character 猫 not found");
    if(dog)
        printf("The character 犬 found at position %td\n", dog-arr);
    else
        puts("The character 犬 not found");
}


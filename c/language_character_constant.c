/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_character_constant.exe ./c/language_character_constant.c && (cd ../_build/c/;./language_character_constant.exe)
https://en.cppreference.com/w/c/language/character_constant
*/
#include <stddef.h>
#include <stdio.h>
#include <uchar.h>
int main(void)
{
    printf("constant value     \n");
    printf("-------- ----------\n");
    // integer character constants,
    int c1='a'; printf("'a':\t %#010x\n", c1);
    int c2='๐'; printf("'๐':\t %#010x\n\n", c2); // implementation-defined
    // multicharacter constant
    int c3='ab'; printf("'ab':\t %#010x\n\n", c3); // implementation-defined
    // 16-bit wide character constants
    char16_t uc1 = u'a'; printf("'a':\t %#010x\n", (int)uc1);
    char16_t uc2 = u'ยข'; printf("'ยข':\t %#010x\n", (int)uc2);
    char16_t uc3 = u'็ซ'; printf("'็ซ':\t %#010x\n", (int)uc3);
    // implementation-defined (๐ maps to two 16-bit characters)
    char16_t uc4 = u'๐'; printf("'๐':\t %#010x\n\n", (int)uc4);
    // 32-bit wide character constants
    char32_t Uc1 = U'a'; printf("'a':\t %#010x\n", (int)Uc1);
    char32_t Uc2 = U'ยข'; printf("'ยข':\t %#010x\n", (int)Uc2);
    char32_t Uc3 = U'็ซ'; printf("'็ซ':\t %#010x\n", (int)Uc3);
    char32_t Uc4 = U'๐'; printf("'๐':\t %#010x\n\n", (int)Uc4);
    // wide character constants
    wchar_t wc1 = L'a'; printf("'a':\t %#010x\n", (int)wc1);
    wchar_t wc2 = L'ยข'; printf("'ยข':\t %#010x\n", (int)wc2);
    wchar_t wc3 = L'็ซ'; printf("'็ซ':\t %#010x\n", (int)wc3);
    wchar_t wc4 = L'๐'; printf("'๐':\t %#010x\n\n", (int)wc4);
}


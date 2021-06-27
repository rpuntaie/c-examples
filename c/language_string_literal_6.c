/*
gcc -std=c99 -pthread -o ../_build/c/language_string_literal_6.exe ./c/language_string_literal_6.c && (cd ../_build/c/;./language_string_literal_6.exe)
https://en.cppreference.com/w/c/language/string_literal
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <uchar.h>
#include <locale.h>
int main(void)
{
    char s1[] = "a猫🍌"; // or "a\u732B\U0001F34C"
    char s2[] = u8"a猫🍌";
    char16_t s3[] = u"a猫🍌";
    char32_t s4[] = U"a猫🍌";
    wchar_t s5[] = L"a猫🍌";
    setlocale(LC_ALL, "en_US.utf8");
    printf("  \"%s\" is a char[%zu] holding     { ", s1, sizeof s1 / sizeof *s1);
    for(size_t n = 0; n < sizeof s1 / sizeof *s1; ++n) 
        printf("0x%02X ", +(unsigned char)s1[n]); 
    puts("}");
    printf("u8\"%s\" is a char[%zu] holding     { ", s2, sizeof s2 / sizeof *s2);
    for(size_t n = 0; n < sizeof s2 / sizeof *s2; ++n) 
       printf("0x%02X ", +(unsigned char)s2[n]); 
    puts("}");
    printf(" u\"a猫🍌\" is a char16_t[%zu] holding { ", sizeof s3 / sizeof *s3);
    for(size_t n = 0; n < sizeof s3 / sizeof *s3; ++n) 
       printf("0x%04X ", s3[n]); 
    puts("}");
    printf(" U\"a猫🍌\" is a char32_t[%zu] holding { ", sizeof s4 / sizeof *s4);
    for(size_t n = 0; n < sizeof s4 / sizeof *s4; ++n) 
       printf("0x%08X ", s4[n]); 
    puts("}");
    printf(" L\"%ls\" is a wchar_t[%zu] holding  { ", s5, sizeof s5 / sizeof *s5);
    for(size_t n = 0; n < sizeof s5 / sizeof *s5; ++n) 
       printf("0x%08X ", (unsigned)s5[n]); 
    puts("}");
}


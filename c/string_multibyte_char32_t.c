/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_multibyte_char32_t.exe ./c/string_multibyte_char32_t.c && (cd ../_build/c/;./string_multibyte_char32_t.exe)
https://en.cppreference.com/w/c/string/multibyte/char32_t
*/
#include <uchar.h>
#include <stdio.h>
int main(void)
{
    char32_t wc[] = U"zß水🍌"; // or "z\u00df\u6c34\U0001f34c"
    size_t wc_sz = sizeof wc / sizeof *wc;
    printf("%zu UTF-32 code units: [ ", wc_sz);
    for (size_t n = 0; n < wc_sz; ++n) printf("%#x ", wc[n]);
    printf("]\n");
}


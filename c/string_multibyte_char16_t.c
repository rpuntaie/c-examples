/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_multibyte_char16_t.exe ./c/string_multibyte_char16_t.c && (cd ../_build/c/;./string_multibyte_char16_t.exe)
https://en.cppreference.com/w/c/string/multibyte/char16_t
*/
#include <uchar.h>
#include <stdio.h>
int main(void)
{
    char16_t wcs[] = u"zß水🍌"; // or "z\u00df\u6c34\U0001f34c"
    size_t wcs_sz = sizeof wcs / sizeof *wcs;
    printf("%zu UTF-16 code units: [ ", wcs_sz);
    for (size_t n = 0; n < wcs_sz; ++n) printf("%#x ", wcs[n]);
    printf("]\n");
}


/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_multibyte_mbrtowc.exe ./c/string_multibyte_mbrtowc.c && (cd ../_build/c/;./string_multibyte_mbrtowc.exe)
https://en.cppreference.com/w/c/string/multibyte/mbrtowc
*/
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    mbstate_t state;
    memset(&state, 0, sizeof state);
    char in[] = u8"z\u00df\u6c34\U0001F34C"; // or u8"zß水🍌"
    size_t in_sz = sizeof in / sizeof *in;
    printf("Processing %zu UTF-8 code units: [ ", in_sz);
    for(size_t n = 0; n < in_sz; ++n) printf("%#x ", (unsigned char)in[n]);
    puts("]");
    wchar_t out[in_sz];
    char *p_in = in, *end = in + in_sz;
    wchar_t *p_out = out;
    int rc;
    while((rc = mbrtowc(p_out, p_in, end - p_in, &state)) > 0)
    {
        p_in += rc;
        p_out += 1;
    }
    size_t out_sz = p_out - out + 1;
    printf("into %zu wchar_t units: [ ", out_sz);
    for(size_t x = 0; x < out_sz; ++x) printf("%#x ", out[x]);
    puts("]");
}


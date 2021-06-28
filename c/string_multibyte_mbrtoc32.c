/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/string_multibyte_mbrtoc32.exe ./c/string_multibyte_mbrtoc32.c && (cd ../_build/c/;./string_multibyte_mbrtoc32.exe)
https://en.cppreference.com/w/c/string/multibyte/mbrtoc32
*/
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <uchar.h>
#include <assert.h>
mbstate_t state;
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    char in[] = u8"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"
    size_t in_sz = sizeof in / sizeof *in;
    printf("Processing %zu UTF-8 code units: [ ", in_sz);
    for(size_t n = 0; n < in_sz; ++n) printf("%#x ", (unsigned char)in[n]);
    puts("]");
    char32_t out[in_sz];
    char *p_in = in, *end = in + in_sz;
    char32_t *p_out = out;
    size_t rc;
    while((rc = mbrtoc32(p_out, p_in, end - p_in, &state)))
    {
        assert(rc != (size_t)-3); // no surrogate pairs in UTF-32
        if(rc == (size_t)-1) break; // invalid input
        if(rc == (size_t)-2) break; // truncated input
        p_in += rc;
        p_out += 1;
    }
    size_t out_sz = p_out - out + 1;
    printf("into %zu UTF-32 code units: [ ", out_sz);
    for(size_t x = 0; x < out_sz; ++x) printf("%#x ", out[x]);
    puts("]");
}


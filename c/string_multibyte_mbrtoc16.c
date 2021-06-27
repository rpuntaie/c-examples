/*
gcc -std=c99 -pthread -o ../_build/c/string_multibyte_mbrtoc16.exe ./c/string_multibyte_mbrtoc16.c && (cd ../_build/c/;./string_multibyte_mbrtoc16.exe)
https://en.cppreference.com/w/c/string/multibyte/mbrtoc16
*/
#include <stdio.h>
#include <locale.h>
#include <uchar.h>
mbstate_t state;
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    char in[] = u8"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"
    size_t in_sz = sizeof in / sizeof *in;
    printf("Processing %zu UTF-8 code units: [ ", in_sz);
    for(size_t n = 0; n < in_sz; ++n) printf("%#x ", (unsigned char)in[n]);
    puts("]");
    char16_t out[in_sz];
    char *p_in = in, *end = in + in_sz;
    char16_t *p_out = out;
    size_t rc;
    while((rc = mbrtoc16(p_out, p_in, end - p_in, &state)))
    {
        if(rc == (size_t)-1)      // invalid input
            break;
        else if(rc == (size_t)-2) // truncated input
            break;
        else if(rc == (size_t)-3) // UTF-16 high surrogate
            p_out += 1;
        else {
            p_in += rc;
            p_out += 1;
        };
    }
    size_t out_sz = p_out - out + 1;
    printf("into %zu UTF-16 code units: [ ", out_sz);
    for(size_t x = 0; x < out_sz; ++x) printf("%#x ", out[x]);
    puts("]");
}


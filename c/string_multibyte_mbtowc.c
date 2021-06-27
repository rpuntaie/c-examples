/*
gcc -std=c99 -pthread -o ../_build/c/string_multibyte_mbtowc.exe ./c/string_multibyte_mbtowc.c && (cd ../_build/c/;./string_multibyte_mbtowc.exe)
https://en.cppreference.com/w/c/string/multibyte/mbtowc
*/
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
// print multibyte string to wide-oriented stdout
// equivalent to wprintf(L"%s\n", ptr);
void print_mb(const char* ptr)
{
    mbtowc(NULL, 0, 0); // reset the conversion state
    const char* end = ptr + strlen(ptr);
    int ret;
    for (wchar_t wc; (ret = mbtowc(&wc, ptr, end-ptr)) > 0; ptr+=ret) {
        wprintf(L"%lc", wc);
    }
    wprintf(L"\n");
}
int main(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    // UTF-8 narrow multibyte encoding
    print_mb(u8"z\u00df\u6c34\U0001F34C"); // or u8"zß水🍌"
}


/*
gcc -std=c99 -pthread -o ../_build/c/string_byte_strxfrm.exe ./c/string_byte_strxfrm.c && (cd ../_build/c/;./string_byte_strxfrm.exe)
https://en.cppreference.com/w/c/string/byte/strxfrm
*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
int main(void)
{
    setlocale(LC_COLLATE, "cs_CZ.iso88592");
    const char *in1 = "hrnec";
    char out1[1+strxfrm(NULL, in1, 0)];
    strxfrm(out1, in1, sizeof out1);
    const char *in2 = "chrt";
    char out2[1+strxfrm(NULL, in2, 0)];
    strxfrm(out2, in2, sizeof out2);
    printf("In the Czech locale: ");
    if(strcmp(out1, out2) < 0)
         printf("%s before %s\n",in1, in2);
    else
         printf("%s before %s\n",in2, in1);
    printf("In lexicographical comparison: ");
    if(strcmp(in1, in2)<0)
         printf("%s before %s\n",in1, in2);
    else
         printf("%s before %s\n",in2, in1);
}


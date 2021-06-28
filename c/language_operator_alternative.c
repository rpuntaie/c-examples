/*
gcc -std=c17 -lc -lm -pthread -o ../_build/c/language_operator_alternative.exe ./c/language_operator_alternative.c && (cd ../_build/c/;./language_operator_alternative.exe)
https://en.cppreference.com/w/c/language/operator_alternative
*/
%:include <stdlib.h>
%:include <stdio.h>
%:include <iso646.h>
int main(int argc, char** argv)
??<
    if (argc > 1 and argv<:1:> not_eq NULL)
    <%
       printf("Hello%s\n", argv<:1:>);
    %>
    return EXIT_SUCCESS;
??>


/*
gcc -std=c99 -pthread -o ../_build/c/language_operator_member_access_2.exe ./c/language_operator_member_access_2.c && (cd ../_build/c/;./language_operator_member_access_2.exe)
https://en.cppreference.com/w/c/language/operator_member_access
*/
int f(char c) { return c;}
int main(void)
{
   int n = 1;
   int *p = &n; // address of object n
   int (*fp)(char) = &f; // address of function f
   int a[3] = {1,2,3};
   int *beg=a, *end=&a[3]; // same as end = n+3
}


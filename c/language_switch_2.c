/*
gcc -std=c99 -pthread -o ../_build/c/language_switch_2.exe ./c/language_switch_2.c && (cd ../_build/c/;./language_switch_2.exe)
https://en.cppreference.com/w/c/language/switch
*/
#include <stdio.h>
void func(int x)
{
   printf("func(%d): ", x);
   switch(x)
   {
      case 1: printf("case 1, ");
      case 2: printf("case 2, ");
      case 3: printf("case 3.\n"); break;
      case 4: printf("case 4, ");
      case 5: printf("case 5, ");
      default: printf("default.\n");
   }
}
int main(void)
{
   for(int i = 1; i < 9; ++i) func(i);
}


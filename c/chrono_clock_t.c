/*
gcc -std=c99 -pthread -o ../_build/c/chrono_clock_t.exe ./c/chrono_clock_t.c && (cd ../_build/c/;./chrono_clock_t.exe)
https://en.cppreference.com/w/c/chrono/clock_t
*/
#include <stdio.h>
#include <time.h>
volatile unsigned sink;
int main (void)
{
  clock_t start = clock();
  for(size_t i=0; i<10000000; ++i)
      sink++;
  clock_t end = clock();
  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("for loop took %f seconds to execute \n", cpu_time_used);
}


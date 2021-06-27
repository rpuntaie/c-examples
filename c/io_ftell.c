/*
gcc -std=c99 -pthread -o ../_build/c/io_ftell.exe ./c/io_ftell.c && (cd ../_build/c/;./io_ftell.exe)
https://en.cppreference.com/w/c/io/ftell
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    /* Prepare an array of f-p values. */
    #define SIZE 5
    double A[SIZE] = {1.,2.,3.,4.,5.};
    /* Write array to a file. */
    FILE * fp = fopen("test.bin", "wb");
    fwrite(A,sizeof(double),SIZE,fp);
    fclose (fp);
    /* Read the f-p values into array B. */
    double B[SIZE];
    fp = fopen("test.bin","rb");
    long int pos = ftell(fp);   /* position indicator at start of file */
    if (pos == -1L)
    {
       perror("ftell()");
       fprintf(stderr,"ftell() failed in file %s at line # %d\n", __FILE__,__LINE__-4);
       exit(EXIT_FAILURE);
    }
    printf("%ld\n", pos);
    int ret_code = fread(B,sizeof(double),1,fp);   /* read one f-p value */
    pos = ftell(fp);   /* position indicator after reading one f-p value */
    if (pos == -1L)
    {
       perror("ftell()");
       fprintf(stderr,"ftell() failed in file %s at line # %d\n", __FILE__,__LINE__-4);
       exit(EXIT_FAILURE);
    }
    printf("%ld\n", pos);
    printf("%.1f\n", B[0]);   /* print one f-p value */
    return EXIT_SUCCESS; 
}


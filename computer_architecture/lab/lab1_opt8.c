#include <stdio.h>

int main()
{
    int a = 2, b = 4, mul, sum, dif;

    __asm__ ( "imull %%ebx, %%eax;" : "=a" (mul) : "a" (a) , "b" (b) );
    __asm__ ( "addl %%ebx, %%eax;" : "=a" (sum) : "a" (a) , "b" (b) );
    __asm__ ( "subl %%ebx, %%eax;" : "=a" (dif) : "a" (mul) , "b" (sum) );

    printf( "%d * %d = %d\n", a, b, mul );
    printf( "%d + %d = %d\n", a, b, sum );
    printf( "Difference is %d - %d = %d\n", mul, sum, dif );

    return 0;
}

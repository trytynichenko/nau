#include <stdio.h>

double average(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        __asm__ ( "addl %%ebx, %%eax;" : "=a" (sum) : "a" (sum) , "b" (arr[i]) );

    return (float)sum / n;
}

int maximum(int arr[], int n)
{
    int max;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

int main()
{
    int fib[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int n = sizeof(fib)/sizeof(fib[0]);
    float avg;

    for (int i = 0; i < n; i++)
        printf("Fibonacci number [%d] = %d\n", i, fib[i] );

    printf("Average = %.2f\n", average(fib, n));
    printf("Max = %d\n", maximum(fib, n));

    return 0;
}

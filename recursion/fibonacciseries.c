#include <stdio.h>
int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
void main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    printf("The fibonacci series of %d numbers are:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", fib(i));
    }
}
#include <stdio.h>
int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
void main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int r = fact(n);
    printf("fact of %d is %d", n, r);
}
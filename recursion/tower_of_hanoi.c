#include <stdio.h>

void toh(int n, char s, char i, char d)
{
    if (n == 0)
        return;
    toh(n - 1, s, d, i);
    printf("Ring %d is moved from %c to %c\n", n, s, d);
    toh(n - 1, i, s, d);
}

int main() // Changed return type to int
{
    int n;
    printf("Enter the number of rings to be arranged: ");
    scanf("%d", &n);
    
    toh(n, 'A', 'B', 'C'); // Calling the toh function
    return 0; // Added return statement
}
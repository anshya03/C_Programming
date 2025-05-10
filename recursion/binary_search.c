#include <stdio.h>
int bin_search(int a[], int k, int l, int h)
{
    if (l > h)
        return 0;
    int mid = (l + h) / 2;
    if (a[mid] == k)
        return mid;
    else if (a[mid] > k)
        return bin_search(a, k, l, mid - 1);
    else
        return bin_search(a, k, mid + 1, h);
}
void main()
{
    int n, k;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d:", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &k);
    int r = bin_search(a, k, 0, n - 1);
    if (r != 0)
        printf("The element %d is found at %dth position", k, r);
    else
        printf("The element is not found!");
}
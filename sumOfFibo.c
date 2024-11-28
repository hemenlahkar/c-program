#include <stdio.h>

int sum(int n)
{
    if (n == 1 || n == 2 || n == 3)
        return n - 1;
    return 2 * sum(n - 1) - sum(n - 3);
}

int main()
{
    int n;
    printf("Eneter the no. of terms of the fibonacci series: ");
    scanf("%d", &n);
    printf("\nThe sum of the first %d terms of the fibonacci series is: %d\n", n, sum(n));
    return 0;
}
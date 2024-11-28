#include<stdio.h>

void toh(int n, char source, char aux, char destination)
{
    if(n == 1)
        printf("\n%c -> %c",source,destination);
    else
    {
        toh(n - 1, source, destination, aux);
        printf("\n%c -> %c", source, destination);
        toh(n-1, aux, source, destination);
    }
}

int main()
{
    int n;
    printf("Enter the no of disc: ");
    scanf("%d", &n);
    toh(n, 'S', 'A', 'D');
    return 0;
}
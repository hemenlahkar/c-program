#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) /*Command line argument*/
{
    int sum = 0;
    for (int i = 1; i < argc; i++)
        sum += atoi(argv[i]);
    printf("Required sum = %d", sum);
    return 0;
}
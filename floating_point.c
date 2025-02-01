#include <stdio.h>

void printBits(void *ptr, size_t size)
{
    const unsigned char *byte_ptr = (const unsigned char *)ptr;
    for (int i = size - 1; i >= 0; i--)
    {
        unsigned char byte = byte_ptr[i];
        for (int j = 7; j >= 0; j--)
        {
            printf("%d", (byte >> j) & 1);
            if ((i == size - 1 || i == size - 2) && j == 7)
            {
                printf(" ");
            }
        }
    }
    printf("\n");
}
int main()
{
    float x;
    printf("Enter a float number: ");
    scanf("%f", &x);
    printBits(&x, 4);
    return 0;
}
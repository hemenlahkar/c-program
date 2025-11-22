#include <stdio.h>
#include <windows.h>

int main()
{
    for (int i = 0; i <= 100; i += 2)
    {
        int j;
        putchar('[');
        for (j = 0; j <= i; j += 2)
            printf("#");
        while (j < 100)
        {
            putchar('.');
            j += 2;
        }
        printf("] %3d/100\r", i);
        Sleep(1000);
    }
    putchar('\n');
    return 0;
}
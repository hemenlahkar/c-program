#include <stdio.h>
#include <stdarg.h>

int sum(int max, ...);

int main()
{
    printf("%d ", sum(2, 5, 7));
    printf("\n");
    printf("%d ", sum(3, 3, 5, 9));
    return 0;
}

int sum(int max, ...)
{
    va_list arg_ptr;
    int s = 0, args;
    va_start(arg_ptr, max);
    args = 0;
    while (args < max)
    {
        s += va_arg(arg_ptr, int);
        args++;
    }
    va_end(arg_ptr);
    return s;
}
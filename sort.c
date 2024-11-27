#include <stdio.h>
#include <stdlib.h>

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                a[i] = a[i] ^ a[j];
                a[j] = a[i] ^ a[j];
                a[i] = a[i] ^ a[j];
            }
        }
    }
}

void bubble_sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                a[j] = a[j] ^ a[j + 1];
                a[j + 1] = a[j] ^ a[j + 1];
                a[j] = a[j] ^ a[j + 1];
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        t = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > t; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = t;
    }
}

int main()
{
    int arr[50], i;
    for (i = 0; i < 50; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("\nBefore sorting: ");
    for (i = 0; i < 20; i++)
        printf("%d ", arr[i]);
    insertion_sort(arr, 20);
    printf("\nAfter sorting: ");
    for (i = 0; i < 20; i++)
        printf("%d ", arr[i]);

    return 0;
}
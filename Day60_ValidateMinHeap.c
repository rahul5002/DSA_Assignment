#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    bool isMinHeap = true;
    for (int i = 0; i <= (n - 2) / 2; ++i)
    {
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
        {
            isMinHeap = false;
            break;
        }
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
        {
            isMinHeap = false;
            break;
        }
    }

    if (isMinHeap)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    free(arr);

    return 0;
}
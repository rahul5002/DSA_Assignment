#include <stdio.h>
#include <stdlib.h>

void binaryInsertionSort(int* arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        // Use iterative binary search to find the insertion point
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (key < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // Shift elements to the right to make space for the key
        for (int j = i - 1; j >= left; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[left] = key;
    }
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    binaryInsertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}
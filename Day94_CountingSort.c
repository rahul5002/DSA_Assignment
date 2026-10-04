#include <stdio.h>
#include <stdlib.h>

void countingSort(int* arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    // Step 1: Find the maximum element
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    // Step 2: Build frequency array
    int* count = (int*)calloc(maxVal + 1, sizeof(int));
    if (count == NULL)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Step 3: Compute prefix sums (cumulative counts)
    for (int i = 1; i <= maxVal; i++)
    {
        count[i] += count[i - 1];
    }

    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    // Step 4: Build the output array (traverse backwards to maintain stability)
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    free(count);
    free(output);
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

    countingSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}
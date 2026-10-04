#include <stdio.h>
#include <stdlib.h>

long long mergeAndCount(int* arr, int left, int mid, int right, int* temp)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    long long count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            // All elements remaining in the left subarray from i to mid 
            // are greater than arr[j], forming inversions
            count += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}

long long mergeSortAndCount(int* arr, int left, int right, int* temp)
{
    long long count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        count += mergeSortAndCount(arr, left, mid, temp);
        count += mergeSortAndCount(arr, mid + 1, right, temp);
        count += mergeAndCount(arr, left, mid, right, temp);
    }
    return count;
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

    int* temp = (int*)malloc(n * sizeof(int));
    long long totalInversions = mergeSortAndCount(arr, 0, n - 1, temp);

    printf("%lld\n", totalInversions);

    free(arr);
    free(temp);
    return 0;
}
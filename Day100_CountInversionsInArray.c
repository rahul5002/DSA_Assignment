#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int* indices, int left, int mid, int right, int* tempIndices, int* counts)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (nums[indices[j]] < nums[indices[i]])
        {
            rightCount++;
            tempIndices[k++] = indices[j++];
        }
        else
        {
            counts[indices[i]] += rightCount;
            tempIndices[k++] = indices[i++];
        }
    }

    while (i <= mid)
    {
        counts[indices[i]] += rightCount;
        tempIndices[k++] = indices[i++];
    }

    while (j <= right)
    {
        tempIndices[k++] = indices[j++];
    }

    for (i = left; i <= right; i++)
    {
        indices[i] = tempIndices[i];
    }
}

void mergeSort(int* nums, int* indices, int left, int right, int* tempIndices, int* counts)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(nums, indices, left, mid, tempIndices, counts);
    mergeSort(nums, indices, mid + 1, right, tempIndices, counts);
    merge(nums, indices, left, mid, right, tempIndices, counts);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int* counts = (int*)calloc(n, sizeof(int));
    int* indices = (int*)malloc(n * sizeof(int));
    int* tempIndices = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }

    mergeSort(nums, indices, 0, n - 1, tempIndices, counts);

    for (int i = 0; i < n; i++)
    {
        printf("%d%s", counts[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(nums);
    free(counts);
    free(indices);
    free(tempIndices);
    return 0;
}
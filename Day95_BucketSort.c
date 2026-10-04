#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double* data;
    int size;
    int capacity;
} Bucket;

void insertionSort(double* arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bucketSort(double* arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    // Step 1: Create n buckets
    Bucket* buckets = (Bucket*)malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++)
    {
        buckets[i].size = 0;
        buckets[i].capacity = 2;
        buckets[i].data = (double*)malloc(buckets[i].capacity * sizeof(double));
    }

    // Step 2: Distribute array elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bi = (int)(n * arr[i]);
        if (bi >= n)
        {
            bi = n - 1; // Safeguard for boundary value 1.0
        }
        if (bi < 0)
        {
            bi = 0;
        }

        if (buckets[bi].size >= buckets[bi].capacity)
        {
            buckets[bi].capacity *= 2;
            buckets[bi].data = (double*)realloc(buckets[bi].data, buckets[bi].capacity * sizeof(double));
        }

        buckets[bi].data[buckets[bi].size++] = arr[i];
    }

    // Step 3: Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++)
    {
        if (buckets[i].size > 0)
        {
            insertionSort(buckets[i].data, buckets[i].size);
        }
    }

    // Step 4: Concatenate buckets back into the original array
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size; j++)
        {
            arr[index++] = buckets[i].data[j];
        }
        free(buckets[i].data);
    }
    
    free(buckets);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%.4f%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}
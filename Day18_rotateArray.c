#include <stdio.h>
#include <stdlib.h>

void reverse(int* arr, int start, int end) 
{
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() 
{
    int n, k;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        return 1; 
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        return 1; 
    }
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    if (scanf("%d", &k) != 1) 
    {
        free(arr);
        return 1;
    }
    k = k % n;
    if (k > 0) 
    {
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
    }
    for (int i = 0; i < n; i++) 
    {
        printf("%d", arr[i]);
        if (i < n - 1) 
        {
            printf(" "); 
        }
    }
    printf("\n");

    free(arr);
    return 0;
}
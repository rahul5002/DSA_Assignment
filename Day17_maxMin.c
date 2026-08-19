#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
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
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max_val) 
        {
            max_val = arr[i];
        }
        if (arr[i] < min_val) 
        {
            min_val = arr[i];
        }
    }
    printf("Max: %d\n", max_val);
    printf("Min: %d\n", min_val);

    free(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) 
    {
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    if (n < 2) 
    {
        printf("Invalid input: Array must have at least 2 elements.\n");
        free(arr);
        return 1;
    }
    qsort(arr, n, sizeof(int), compare);
    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int res_left_val = 0;
    int res_right_val = 0;
    while (left < right) 
    {
        int current_sum = arr[left] + arr[right];
        if (abs(current_sum) < abs(min_sum)) 
        {
            min_sum = current_sum;
            res_left_val = arr[left];
            res_right_val = arr[right];
        }
        if (current_sum < 0) 
        {
            left++;  
        } 
        else if (current_sum > 0) 
        {
            right--; 
        } 
        else 
        {
            break;  
        }
    }
    printf("%d %d\n", res_left_val, res_right_val);
    
    free(arr);
    return 0;
}
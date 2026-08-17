#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) 
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
    for (int i = 0; i < n; i++) 
    {
        int already_counted = 0;
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                already_counted = 1;
                break;
            }
        }
        if (!already_counted) 
        {
            int count = 0;
            for (int j = i; j < n; j++) 
            {
                if (arr[j] == arr[i]) 
                {
                    count++;
                }
            }
            printf("%d:%d ", arr[i], count);
        }
    }
    printf("\n");
    free(arr);
    
    return 0;
}
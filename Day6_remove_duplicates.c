#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        return 0;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int write_index = 1; 
    for (int read_index = 1; read_index < n; read_index++) 
    {
        if (arr[read_index] != arr[read_index - 1]) 
        {
            arr[write_index] = arr[read_index];
            write_index++;
        }
    }
    for (int i = 0; i < write_index; i++) 
    {
        printf("%d", arr[i]);
        if (i < write_index - 1) 
        {
            printf(" ");
        }
    }
    printf("\n");
    free(arr);
    
    return 0;
}
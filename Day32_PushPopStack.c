#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, m;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        return 0;
    }
    int* stack = (int*)malloc(n * sizeof(int));
    if (stack == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int top = -1;
    for (int i = 0; i < n; i++) 
    {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }
    if (scanf("%d", &m) == 1) 
    {
        for (int i = 0; i < m; i++) 
        {
            if (top >= 0) 
            {
                top--;
            }
        }
    }
    for (int i = top; i >= 0; i--) 
    {
        printf("%d", stack[i]);
        if (i > 0) 
        {
            printf(" ");
        }
    }
    printf("\n");
    free(stack);
    
    return 0;
}
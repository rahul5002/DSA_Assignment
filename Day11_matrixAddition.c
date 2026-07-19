#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) 
    {
        return 1;
    }
    int **matrixA = (int **)malloc(m * sizeof(int *));
    int **matrixB = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) 
    {
        matrixA[i] = (int *)malloc(n * sizeof(int));
        matrixB[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &matrixA[i][j]);
        }
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &matrixB[i][j]);
        }
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int sum = matrixA[i][j] + matrixB[i][j];            
            if (j == n - 1) 
            {
                printf("%d", sum);
            } 
            else 
            {
                printf("%d ", sum);
            }
        }
        printf("\n");
    }    
    for (int i = 0; i < m; i++) 
    {
        free(matrixA[i]);
        free(matrixB[i]);
    }
    free(matrixA);
    free(matrixB);
    
    return 0;
}
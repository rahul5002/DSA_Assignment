#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() 
{
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) 
    {
        return 1;
    }
    if (m != n) 
    {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) 
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    bool isSymmetric = true;
    for (int i = 0; i < m; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (matrix[i][j] != matrix[j][i]) 
            {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) 
        {
            break;
        }
    }
    if (isSymmetric) 
    {
        printf("Symmetric Matrix\n");
    } 
    else 
    {
        printf("Not a Symmetric Matrix\n");
    }
    for (int i = 0; i < m; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}
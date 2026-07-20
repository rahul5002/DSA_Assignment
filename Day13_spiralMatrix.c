#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;
    int matrix[r][c];
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int first = 1;
    while (top <= bottom && left <= right) 
    {
        for (int j = left; j <= right; j++) 
        {
            if (!first) printf(" ");
            printf("%d", matrix[top][j]);
            first = 0;
        }
        top++;
        for (int i = top; i <= bottom; i++) 
        {
            if (!first) printf(" ");
            printf("%d", matrix[i][right]);
            first = 0;
        }
        right--;
        if (top <= bottom) 
        {
            for (int j = right; j >= left; j--) 
            {
                if (!first) printf(" ");
                printf("%d", matrix[bottom][j]);
                first = 0;
            }
            bottom--;
        }
        if (left <= right) 
        {
            for (int i = bottom; i >= top; i--) 
            {
                if (!first) printf(" ");
                printf("%d", matrix[i][left]);
                first = 0;
            }
            left++;
        }
    }

    printf("\n");
    return 0;
}
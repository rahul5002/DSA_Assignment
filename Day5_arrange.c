#include <stdio.h>

void mergeLogs(int log1[], int p, int log2[], int q) 
{
    int i = 0; 
    int j = 0; 
    int first = 1;
    while (i < p && j < q) 
    {
        if (!first) printf(" ");
        first = 0;
        if (log1[i] <= log2[j]) 
        {
            printf("%d", log1[i]);
            i++;
        } 
        else 
        {
            printf("%d", log2[j]);
            j++;
        }
    }
    while (i < p) 
    {
        if (!first) printf(" ");
        first = 0;
        printf("%d", log1[i]);
        i++;
    }
    while (j < q) 
    {
        if (!first) printf(" ");
        first = 0;
        printf("%d", log2[j]);
        j++;
    }
    printf("\n");
}
int main() 
{
    int p, q;
    if (scanf("%d", &p) != 1) return 0;
    int log1[p];
    for (int i = 0; i < p; i++) 
    {
        scanf("%d", &log1[i]);
    }
    if (scanf("%d", &q) != 1) return 0;
    int log2[q];
    for (int i = 0; i < q; i++) 
    {
        scanf("%d", &log2[i]);
    }
    mergeLogs(log1, p, log2, q);

    return 0;
}
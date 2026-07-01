#include <stdio.h>

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    int comparisons = 0;
    int foundIndex = -1; 
    for (int i = 0; i < n; i++) 
    {
        comparisons++; 
        if (arr[i] == k) 
        {
            foundIndex = i;
            break; 
        }
    }
    if (foundIndex != -1) 
    {
        printf("Found at index %d\n", foundIndex);
    } 
    else 
    {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}
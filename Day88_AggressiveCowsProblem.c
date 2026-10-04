#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    
    if (int_a < int_b)
    {
        return -1;
    }
    if (int_a > int_b)
    {
        return 1;
    }
    return 0;
}

int canPlace(int* stalls, int n, int k, int minDist)
{
    int count = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPos >= minDist)
        {
            count++;
            lastPos = stalls[i];
            
            if (count >= k)
            {
                return 1;
            }
        }
    }
    
    return 0;
}

int main()
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2 || n <= 0)
    {
        return 0;
    }

    int* stalls = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions to enable binary search and greedy placement
    qsort(stalls, n, sizeof(int), compare);

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canPlace(stalls, n, k, mid))
        {
            ans = mid;
            left = mid + 1; // Try for a larger minimum distance
        }
        else
        {
            right = mid - 1; // Distance is too large, reduce it
        }
    }

    printf("%d\n", ans);

    free(stalls);
    return 0;
}
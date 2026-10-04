#include <stdio.h>
#include <stdlib.h>

int canAllocate(int* pages, int n, int m, long long maxPages)
{
    int students = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pages[i] > maxPages)
        {
            return 0;
        }

        if (currentSum + pages[i] > maxPages)
        {
            students++;
            currentSum = pages[i];
        }
        else
        {
            currentSum += pages[i];
        }
    }

    return students <= m;
}

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0 || m > n)
    {
        return 0;
    }

    int* pages = (int*)malloc(n * sizeof(int));
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
        if (pages[i] > left)
        {
            left = pages[i];
        }
        right += pages[i];
    }

    long long ans = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (canAllocate(pages, n, m, mid))
        {
            ans = mid;
            right = mid - 1; // Try for a smaller maximum limit
        }
        else
        {
            left = mid + 1; // Limit is too small, increase it
        }
    }

    printf("%lld\n", ans);

    free(pages);
    return 0;
}
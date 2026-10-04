#include <stdio.h>
#include <stdlib.h>

int canPaint(int* boards, int n, int k, long long maxTime)
{
    int painters = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (boards[i] > maxTime)
        {
            return 0;
        }

        if (currentSum + boards[i] > maxTime)
        {
            painters++;
            currentSum = boards[i];
        }
        else
        {
            currentSum += boards[i];
        }
    }

    return painters <= k;
}

int main()
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2 || n <= 0 || k <= 0)
    {
        return 0;
    }

    int* boards = (int*)malloc(n * sizeof(int));
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &boards[i]);
        if (boards[i] > left)
        {
            left = boards[i];
        }
        right += boards[i];
    }

    long long ans = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid))
        {
            ans = mid;
            right = mid - 1; // Try for a smaller maximum time limit
        }
        else
        {
            left = mid + 1; // Time limit is too small, increase it
        }
    }

    printf("%lld\n", ans);

    free(boards);
    return 0;
}
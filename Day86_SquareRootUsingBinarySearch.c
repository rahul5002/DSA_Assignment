#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n;
    if (scanf("%lld", &n) != 1 || n < 0)
    {
        return 0;
    }

    if (n == 0 || n == 1)
    {
        printf("%lld\n", n);
        return 0;
    }

    long long left = 1;
    long long right = n;
    long long ans = 0;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (mid * mid == n)
        {
            ans = mid;
            break;
        }

        if (mid * mid < n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
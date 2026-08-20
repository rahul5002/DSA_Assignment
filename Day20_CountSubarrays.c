#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    long long diff = (*(long long*)a - *(long long*)b);
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}
int main() 
{
    int n;
    if (scanf("%d", &n) != 1) 
    {
        return 1;
    }
    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));
    prefix[0] = 0;
    long long current_sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        long long val;
        scanf("%lld", &val);
        current_sum += val;
        prefix[i] = current_sum;
    }
    qsort(prefix, n + 1, sizeof(long long), compare);
    long long total_zero_subarrays = 0;
    long long count = 1;
    for (int i = 1; i <= n; i++) 
    {
        if (prefix[i] == prefix[i - 1]) 
        {
            count++;
        } 
        else 
        {
            total_zero_subarrays += (count * (count - 1)) / 2;
            count = 1; 
        }
    }
    total_zero_subarrays += (count * (count - 1)) / 2;
    printf("%lld\n", total_zero_subarrays);
    
    free(prefix);
    return 0;
}
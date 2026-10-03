#include <stdio.h>
#include <stdlib.h>

struct Element
{
    long long sum;
    int index;
};

int compare(const void* a, const void* b)
{
    struct Element* e1 = (struct Element*)a;
    struct Element* e2 = (struct Element*)b;
    
    if (e1->sum != e2->sum)
    {
        if (e1->sum < e2->sum)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    
    return e1->index - e2->index;
}

int main()
{
    int capacity = 10;
    int n = 0;
    long long* arr = (long long*)malloc(capacity * sizeof(long long));
    
    long long val;
    while (scanf("%lld", &val) == 1)
    {
        if (n >= capacity)
        {
            capacity *= 2;
            arr = (long long*)realloc(arr, capacity * sizeof(long long));
        }
        arr[n++] = val;
    }

    if (n == 0)
    {
        printf("0\n");
        free(arr);
        return 0;
    }

    struct Element* prefix = (struct Element*)malloc((n + 1) * sizeof(struct Element));
    prefix[0].sum = 0;
    prefix[0].index = -1;

    long long current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];
        prefix[i + 1].sum = current_sum;
        prefix[i + 1].index = i;
    }

    qsort(prefix, n + 1, sizeof(struct Element), compare);

    int max_len = 0;
    int i = 0;
    while (i <= n)
    {
        int j = i;
        while (j <= n && prefix[j].sum == prefix[i].sum)
        {
            j++;
        }
        
        int len = prefix[j - 1].index - prefix[i].index;
        if (len > max_len)
        {
            max_len = len;
        }
        i = j;
    }

    printf("%d\n", max_len);

    free(arr);
    free(prefix);

    return 0;
}
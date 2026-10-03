#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }

    long long** dist = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++)
    {
        dist[i] = (long long*)malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++)
        {
            long long val;
            scanf("%lld", &val);
            
            if (val == -1 && i != j)
            {
                dist[i][j] = 1000000000000LL;
            }
            else if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = val;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != 1000000000000LL && dist[k][j] != 1000000000000LL)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] >= 1000000000000LL)
            {
                printf("-1");
            }
            else
            {
                printf("%lld", dist[i][j]);
            }
            
            if (j < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(dist[i]);
    }
    free(dist);

    return 0;
}
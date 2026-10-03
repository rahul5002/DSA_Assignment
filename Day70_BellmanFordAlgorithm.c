#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge
{
    int u;
    int v;
    int weight;
};

int main()
{
    int n, m;

    if (scanf("%d %d", &n, &m) != 2)
    {
        return 0;
    }

    struct Edge* edges = (struct Edge*)malloc(m * sizeof(struct Edge));

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    int s;
    scanf("%d", &s);

    int* dist = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    int negativeCycle = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            negativeCycle = 1;
            break;
        }
    }

    if (negativeCycle)
    {
        printf("NEGATIVE CYCLE\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i]);
            }
        }
        printf("\n");
    }

    free(edges);
    free(dist);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int is_directed;

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &is_directed);

    printf("Enter number of vertices (n) and edges (m): ");
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter the %d edges (u v):\n", m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        
        if (is_directed == 0)
        {
            adj[v][u] = 1;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(adj[i]);
    }
    free(adj);

    return 0;
}
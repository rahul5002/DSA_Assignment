#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* createNode(int v, int w)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

int minDistance(int* dist, bool* sptSet, int V)
{
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

int main()
{
    int n, m;
    
    if (scanf("%d %d", &n, &m) != 2)
    {
        return 0;
    }

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
    {
        adjList[i] = NULL;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* newNode1 = createNode(v, w);
        newNode1->next = adjList[u];
        adjList[u] = newNode1;

        struct Node* newNode2 = createNode(u, w);
        newNode2->next = adjList[v];
        adjList[v] = newNode2;
    }

    int s;
    scanf("%d", &s);

    int* dist = (int*)malloc(n * sizeof(int));
    bool* sptSet = (bool*)calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[s] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, sptSet, n);

        if (u == -1) break;

        sptSet[u] = true;

        struct Node* temp = adjList[u];
        while (temp != NULL)
        {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        struct Node* temp = adjList[i];
        while (temp != NULL)
        {
            struct Node* prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    
    free(adjList);
    free(dist);
    free(sptSet);

    return 0;
}
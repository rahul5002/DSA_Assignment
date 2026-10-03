#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void dfs(struct Node** adjList, int vertex, bool* visited)
{
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = adjList[vertex];
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex])
        {
            dfs(adjList, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    int n, m, s;

    printf("Enter number of vertices (n) and edges (m): ");
    scanf("%d %d", &n, &m);

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    bool* visited = (bool*)calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++)
    {
        adjList[i] = NULL;
    }

    printf("Enter the %d edges (u v):\n", m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        struct Node* newNodeRev = createNode(u);
        newNodeRev->next = adjList[v];
        adjList[v] = newNodeRev;
    }

    printf("Enter starting vertex s: ");
    scanf("%d", &s);

    printf("DFS Traversal starting from %d: ", s);
    dfs(adjList, s, visited);
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
    free(visited);

    return 0;
}
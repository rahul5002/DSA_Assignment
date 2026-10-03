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

void dfs(struct Node** adjList, int vertex, bool* visited, int* stack, int* top)
{
    visited[vertex] = true;

    struct Node* temp = adjList[vertex];
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex])
        {
            dfs(adjList, connectedVertex, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = vertex;
}

int main()
{
    int n, m;
    
    if (scanf("%d %d", &n, &m) != 2)
    {
        return 0;
    }

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        adjList[i] = NULL;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adjList, i, visited, stack, &top);
        }
    }

    while (top >= 0)
    {
        printf("%d ", stack[top--]);
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
    free(visited);
    free(stack);

    return 0;
}
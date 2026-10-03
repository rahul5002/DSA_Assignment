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

bool dfs(struct Node** adjList, int vertex, int parent, bool* visited)
{
    visited[vertex] = true;

    struct Node* temp = adjList[vertex];
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (!visited[connectedVertex])
        {
            if (dfs(adjList, connectedVertex, vertex, visited))
            {
                return true;
            }
        }
        else if (connectedVertex != parent)
        {
            return true;
        }
        
        temp = temp->next;
    }

    return false;
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

    for (int i = 0; i < n; i++)
    {
        adjList[i] = NULL;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode1 = createNode(v);
        newNode1->next = adjList[u];
        adjList[u] = newNode1;

        struct Node* newNode2 = createNode(u);
        newNode2->next = adjList[v];
        adjList[v] = newNode2;
    }

    bool hasCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(adjList, i, -1, visited))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

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
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node* next;
};

void addEdge(struct Node** adj, int u, int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int u, struct Node** adj, int* visited, int* count)
{
    visited[u] = 1;
    (*count)++;
    struct Node* temp = adj[u];
    
    while (temp != NULL)
    {
        int v = temp->vertex;
        
        if (!visited[v])
        {
            dfs(v, adj, visited, count);
        }
        
        temp = temp->next;
    }
}

int main()
{
    int n, m;
    
    if (scanf("%d %d", &n, &m) != 2)
    {
        return 0;
    }

    struct Node** adj = (struct Node**)calloc((n + 1), sizeof(struct Node*));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int* visited = (int*)calloc((n + 1), sizeof(int));
    int count = 0;

    if (n > 0)
    {
        dfs(1, adj, visited, &count);
    }

    if (count == n)
    {
        printf("CONNECTED\n");
    }
    else
    {
        printf("NOT CONNECTED\n");
    }

    for (int i = 1; i <= n; i++)
    {
        struct Node* temp = adj[i];
        while (temp != NULL)
        {
            struct Node* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }
    
    free(adj);
    free(visited);

    return 0;
}
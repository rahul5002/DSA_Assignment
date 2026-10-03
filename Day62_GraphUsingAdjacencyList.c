#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int n, m;
    char is_directed;

    printf("Is the graph directed? (y/n): ");
    scanf(" %c", &is_directed);

    printf("Enter number of vertices (n) and edges (m): ");
    scanf("%d %d", &n, &m);

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
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

        if (is_directed == 'n' || is_directed == 'N')
        {
            struct Node* newNodeRev = createNode(u);
            newNodeRev->next = adjList[v];
            adjList[v] = newNodeRev;
        }
    }

    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++)
    {
        struct Node* temp = adjList[i];
        printf("%d: ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
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

    return 0;
}
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

void bfs(struct Node** adjList, int n, int startVertex)
{
    bool* visited = (bool*)calloc(n, sizeof(bool));
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = adjList[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

int main()
{
    int n, m, s;

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

        struct Node* newNodeRev = createNode(u);
        newNodeRev->next = adjList[v];
        adjList[v] = newNodeRev;
    }

    printf("Enter starting vertex s: ");
    scanf("%d", &s);

    printf("BFS Traversal starting from %d: ", s);
    bfs(adjList, n, s);
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

    return 0;
}
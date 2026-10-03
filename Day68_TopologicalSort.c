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
    
    if (scanf("%d %d", &n, &m) != 2)
    {
        return 0;
    }

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    int* inDegree = (int*)calloc(n, sizeof(int));

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
        
        inDegree[v]++;
    }

    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = 0;

    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int* result = (int*)malloc(n * sizeof(int));
    int count = 0;

    while (front < rear)
    {
        int current = queue[front++];
        result[count++] = current;

        struct Node* temp = adjList[current];
        while (temp != NULL)
        {
            int connectedVertex = temp->vertex;
            inDegree[connectedVertex]--;
            
            if (inDegree[connectedVertex] == 0)
            {
                queue[rear++] = connectedVertex;
            }
            
            temp = temp->next;
        }
    }

    if (count == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
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
    free(inDegree);
    free(queue);
    free(result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int vertex;
    int weight;
    struct Node* next;
};

void addEdge(struct Node** adj, int u, int v, int w)
{
    struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
    newNode1->vertex = v;
    newNode1->weight = w;
    newNode1->next = adj[u];
    adj[u] = newNode1;

    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->vertex = u;
    newNode2->weight = w;
    newNode2->next = adj[v];
    adj[v] = newNode2;
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
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int* key = (int*)malloc((n + 1) * sizeof(int));
    int* inMST = (int*)calloc((n + 1), sizeof(int));

    for (int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
    }

    key[1] = 0;
    long long totalWeight = 0;

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        int minVal = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            if (!inMST[i] && key[i] < minVal)
            {
                minVal = key[i];
                u = i;
            }
        }

        if (u == -1)
        {
            break;
        }

        inMST[u] = 1;
        totalWeight += minVal;

        struct Node* temp = adj[u];
        while (temp != NULL)
        {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
            }
            temp = temp->next;
        }
    }

    printf("%lld\n", totalWeight);

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
    free(key);
    free(inMST);

    return 0;
}
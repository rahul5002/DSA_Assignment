#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == -1)
    {
        free(arr);
        return 0;
    }

    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0;
    int rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n)
    {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    struct Node** bfsQueue = (struct Node**)malloc(n * sizeof(struct Node*));
    int bFront = 0;
    int bRear = 0;

    bfsQueue[bRear++] = root;
    int firstPrint = 1;

    while (bFront < bRear)
    {
        int levelSize = bRear - bFront;
        
        for (int j = 0; j < levelSize; ++j)
        {
            struct Node* curr = bfsQueue[bFront++];
            
            if (j == levelSize - 1)
            {
                if (firstPrint)
                {
                    printf("%d", curr->data);
                    firstPrint = 0;
                }
                else
                {
                    printf(" %d", curr->data);
                }
            }
            
            if (curr->left != NULL)
            {
                bfsQueue[bRear++] = curr->left;
            }
            if (curr->right != NULL)
            {
                bfsQueue[bRear++] = curr->right;
            }
        }
    }
    printf("\n");

    free(arr);
    free(queue);
    free(bfsQueue);

    return 0;
}
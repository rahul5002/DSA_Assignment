#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    struct Node** currentLevel = (struct Node**)malloc(n * sizeof(struct Node*));
    struct Node** nextLevel = (struct Node**)malloc(n * sizeof(struct Node*));
    int currTop = -1;
    int nextTop = -1;
    bool leftToRight = true;

    currentLevel[++currTop] = root;
    bool firstPrint = true;

    while (currTop >= 0)
    {
        struct Node* temp = currentLevel[currTop--];
        
        if (firstPrint)
        {
            printf("%d", temp->data);
            firstPrint = false;
        }
        else
        {
            printf(" %d", temp->data);
        }

        if (leftToRight)
        {
            if (temp->left != NULL)
            {
                nextLevel[++nextTop] = temp->left;
            }
            if (temp->right != NULL)
            {
                nextLevel[++nextTop] = temp->right;
            }
        }
        else
        {
            if (temp->right != NULL)
            {
                nextLevel[++nextTop] = temp->right;
            }
            if (temp->left != NULL)
            {
                nextLevel[++nextTop] = temp->left;
            }
        }

        if (currTop == -1)
        {
            leftToRight = !leftToRight;
            struct Node** swap = currentLevel;
            currentLevel = nextLevel;
            nextLevel = swap;
            currTop = nextTop;
            nextTop = -1;
        }
    }
    printf("\n");

    free(arr);
    free(queue);
    free(currentLevel);
    free(nextLevel);

    return 0;
}
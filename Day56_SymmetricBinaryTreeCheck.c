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

bool isMirror(struct Node* leftSub, struct Node* rightSub)
{
    if (leftSub == NULL && rightSub == NULL)
    {
        return true;
    }
    if (leftSub == NULL || rightSub == NULL)
    {
        return false;
    }
    if (leftSub->data != rightSub->data)
    {
        return false;
    }
    return isMirror(leftSub->left, rightSub->right) && isMirror(leftSub->right, rightSub->left);
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
        printf("YES\n");
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

    if (isMirror(root->left, root->right))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    free(arr);
    free(queue);

    return 0;
}
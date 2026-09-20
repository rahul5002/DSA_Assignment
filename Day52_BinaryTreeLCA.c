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

struct Node* lca(struct Node* root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    struct Node* leftLCA = lca(root->left, n1, n2);
    struct Node* rightLCA = lca(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL)
    {
        return root;
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    else
    {
        return rightLCA;
    }
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

    int n1;
    int n2;
    scanf("%d %d", &n1, &n2);

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

    struct Node* ans = lca(root, n1, n2);
    if (ans != NULL)
    {
        printf("%d\n", ans->data);
    }

    free(arr);
    free(queue);

    return 0;
}
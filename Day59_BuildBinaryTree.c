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

int search(int* arr, int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int* inorder, int* postorder, int inStrt, int inEnd, int* pIndex)
{
    if (inStrt > inEnd)
    {
        return NULL;
    }

    struct Node* tNode = createNode(postorder[*pIndex]);
    (*pIndex)--;

    if (inStrt == inEnd)
    {
        return tNode;
    }

    int inIndex = search(inorder, inStrt, inEnd, tNode->data);

    tNode->right = buildTree(inorder, postorder, inIndex + 1, inEnd, pIndex);
    tNode->left = buildTree(inorder, postorder, inStrt, inIndex - 1, pIndex);

    return tNode;
}

void preorder(struct Node* root, int* firstPrint)
{
    if (root == NULL)
    {
        return;
    }

    if (*firstPrint)
    {
        printf("%d", root->data);
        *firstPrint = 0;
    }
    else
    {
        printf(" %d", root->data);
    }

    preorder(root->left, firstPrint);
    preorder(root->right, firstPrint);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int* inorder = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    int* postorder = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &postorder[i]);
    }

    int pIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &pIndex);

    int firstPrint = 1;
    preorder(root, &firstPrint);
    printf("\n");

    free(inorder);
    free(postorder);

    return 0;
}
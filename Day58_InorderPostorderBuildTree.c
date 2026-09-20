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

struct Node* buildTree(int* inorder, int* preorder, int inStrt, int inEnd, int* pIndex)
{
    if (inStrt > inEnd)
    {
        return NULL;
    }

    struct Node* tNode = createNode(preorder[*pIndex]);
    (*pIndex)++;

    if (inStrt == inEnd)
    {
        return tNode;
    }

    int inIndex = search(inorder, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(inorder, preorder, inStrt, inIndex - 1, pIndex);
    tNode->right = buildTree(inorder, preorder, inIndex + 1, inEnd, pIndex);

    return tNode;
}

void postorder(struct Node* root, int* firstPrint)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left, firstPrint);
    postorder(root->right, firstPrint);

    if (*firstPrint)
    {
        printf("%d", root->data);
        *firstPrint = 0;
    }
    else
    {
        printf(" %d", root->data);
    }
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int* preorder = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    int* inorder = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    int pIndex = 0;
    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &pIndex);

    int firstPrint = 1;
    postorder(root, &firstPrint);
    printf("\n");

    free(preorder);
    free(inorder);

    return 0;
}
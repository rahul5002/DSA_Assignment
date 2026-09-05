#include <stdio.h>
#include <stdlib.h>

struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Queue 
{
    int front, rear, capacity;
    struct TreeNode** array;
};

struct Queue* createQueue(int capacity) 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->array = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

int isQueueEmpty(struct Queue* q) 
{
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node) 
{
    q->array[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) 
{
    return q->array[q->front++];
}

struct TreeNode* constructTree(int* arr, int n) 
{
    if (n == 0 || arr[0] == -1) 
    {
        return NULL;
    }

    struct TreeNode* root = createNode(arr[0]);
    struct Queue* q = createQueue(n);
    
    enqueue(q, root);
    int i = 1;
    
    while (i < n && !isQueueEmpty(q)) 
    {
        struct TreeNode* current = dequeue(q);
        
        if (i < n && arr[i] != -1) 
        {
            current->left = createNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;
        
        if (i < n && arr[i] != -1) 
        {
            current->right = createNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }
    
    free(q->array);
    free(q);
    
    return root;
}

void inorder(struct TreeNode* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() 
{
    int n;
    
    if (scanf("%d", &n) != 1) 
    {
        return 0;
    }
    
    if (n <= 0) 
    {
        return 0;
    }
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    struct TreeNode* root = constructTree(arr, n);
    
    inorder(root);
    printf("\n");
    
    free(arr);
    
    return 0;
}
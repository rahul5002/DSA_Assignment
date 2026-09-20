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

struct ListNode
{
    int data;
    struct ListNode* next;
};

struct List
{
    struct ListNode* head;
    struct ListNode* tail;
};

void append(struct List* list, int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = val;
    newNode->next = NULL;
    
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

struct QNode
{
    struct Node* node;
    int hd;
};

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
    free(queue);

    struct List* hash = (struct List*)calloc(2 * n + 1, sizeof(struct List));
    struct QNode* vQueue = (struct QNode*)malloc(n * sizeof(struct QNode));
    
    int vFront = 0;
    int vRear = 0;

    vQueue[vRear].node = root;
    vQueue[vRear].hd = n;
    vRear++;

    int min_hd = n;
    int max_hd = n;

    while (vFront < vRear)
    {
        struct Node* curr = vQueue[vFront].node;
        int hd = vQueue[vFront].hd;
        vFront++;

        append(&hash[hd], curr->data);

        if (curr->left != NULL)
        {
            vQueue[vRear].node = curr->left;
            vQueue[vRear].hd = hd - 1;
            vRear++;
            
            if (hd - 1 < min_hd)
            {
                min_hd = hd - 1;
            }
        }

        if (curr->right != NULL)
        {
            vQueue[vRear].node = curr->right;
            vQueue[vRear].hd = hd + 1;
            vRear++;
            
            if (hd + 1 > max_hd)
            {
                max_hd = hd + 1;
            }
        }
    }

    for (int j = min_hd; j <= max_hd; ++j)
    {
        struct ListNode* curr = hash[j].head;
        if (curr != NULL)
        {
            while (curr != NULL)
            {
                printf("%d", curr->data);
                if (curr->next != NULL)
                {
                    printf(" ");
                }
                struct ListNode* temp = curr;
                curr = curr->next;
                free(temp);
            }
            printf("\n");
        }
    }

    free(arr);
    free(vQueue);
    free(hash);

    return 0;
}
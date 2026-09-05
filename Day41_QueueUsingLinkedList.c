#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Queue 
{
    struct Node *front, *rear;
};

struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) 
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        return -1;
    }

    struct Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) 
    {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

int main() 
{
    int n;
    
    if (scanf("%d", &n) != 1) 
    {
        return 0;
    }
    
    struct Queue* q = createQueue();
    
    for (int i = 0; i < n; i++) 
    {
        char operation[20];
        scanf("%s", operation);
        
        if (strcmp(operation, "enqueue") == 0 || strcmp(operation, "1") == 0) 
        {
            int value;
            scanf("%d", &value);
            enqueue(q, value);
        } 
        else if (strcmp(operation, "dequeue") == 0 || strcmp(operation, "2") == 0) 
        {
            printf("%d\n", dequeue(q));
        }
    }
    
    return 0;
}
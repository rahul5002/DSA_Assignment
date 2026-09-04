#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
    int size;
} Deque;

void initDeque(Deque* dq)
{
    dq->head = NULL;
    dq->tail = NULL;
    dq->size = 0;
}

int empty(Deque* dq)
{
    return dq->size == 0;
}

int size(Deque* dq)
{
    return dq->size;
}

void push_front(Deque* dq, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->head;
    
    if (dq->head != NULL)
    {
        dq->head->prev = newNode;
    }
    
    dq->head = newNode;
    
    if (dq->tail == NULL)
    {
        dq->tail = newNode;
    }
    
    dq->size++;
}

void push_back(Deque* dq, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->tail;
    
    if (dq->tail != NULL)
    {
        dq->tail->next = newNode;
    }
    
    dq->tail = newNode;
    
    if (dq->head == NULL)
    {
        dq->head = newNode;
    }
    
    dq->size++;
}

int pop_front(Deque* dq)
{
    if (empty(dq))
    {
        return -1;
    }
    
    Node* temp = dq->head;
    int val = temp->data;
    
    dq->head = dq->head->next;
    
    if (dq->head != NULL)
    {
        dq->head->prev = NULL;
    }
    else
    {
        dq->tail = NULL;
    }
    
    free(temp);
    dq->size--;
    return val;
}

int pop_back(Deque* dq)
{
    if (empty(dq))
    {
        return -1;
    }
    
    Node* temp = dq->tail;
    int val = temp->data;
    
    dq->tail = dq->tail->prev;
    
    if (dq->tail != NULL)
    {
        dq->tail->next = NULL;
    }
    else
    {
        dq->head = NULL;
    }
    
    free(temp);
    dq->size--;
    return val;
}

int front(Deque* dq)
{
    if (empty(dq))
    {
        return -1;
    }
    
    return dq->head->data;
}

int back(Deque* dq)
{
    if (empty(dq))
    {
        return -1;
    }
    
    return dq->tail->data;
}

void clear(Deque* dq)
{
    while (!empty(dq))
    {
        pop_front(dq);
    }
}

int main()
{
    Deque dq;
    initDeque(&dq);
    
    char op[20];
    
    while (scanf("%s", op) == 1)
    {
        if (strcmp(op, "push_front") == 0)
        {
            int val;
            scanf("%d", &val);
            push_front(&dq, val);
        }
        else if (strcmp(op, "push_back") == 0)
        {
            int val;
            scanf("%d", &val);
            push_back(&dq, val);
        }
        else if (strcmp(op, "pop_front") == 0)
        {
            printf("%d\n", pop_front(&dq));
        }
        else if (strcmp(op, "pop_back") == 0)
        {
            printf("%d\n", pop_back(&dq));
        }
        else if (strcmp(op, "front") == 0)
        {
            printf("%d\n", front(&dq));
        }
        else if (strcmp(op, "back") == 0)
        {
            printf("%d\n", back(&dq));
        }
        else if (strcmp(op, "empty") == 0)
        {
            printf("%d\n", empty(&dq));
        }
        else if (strcmp(op, "size") == 0)
        {
            printf("%d\n", size(&dq));
        }
        else if (strcmp(op, "clear") == 0)
        {
            clear(&dq);
        }
    }
    
    clear(&dq);
    
    return 0;
}
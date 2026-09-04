#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void enqueue(Node** front, Node** rear, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (*rear == NULL)
    {
        *front = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void display(Node* front)
{
    Node* temp = front;
    
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main()
{
    int n;
    
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }
    
    Node* front = NULL;
    Node* rear = NULL;
    
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        enqueue(&front, &rear, val);
    }
    
    display(front);
    
    return 0;
}
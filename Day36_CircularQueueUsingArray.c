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
    
    if (*rear == NULL)
    {
        *front = newNode;
        *rear = newNode;
        newNode->next = *front;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
        (*rear)->next = *front;
    }
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
    
    int m;
    
    if (scanf("%d", &m) == 1)
    {
        for (int i = 0; i < m; i++)
        {
            if (front != NULL)
            {
                front = front->next;
            }
        }
    }
    
    if (front != NULL)
    {
        Node* temp = front;
        
        for (int i = 0; i < n; i++)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        
        printf("\n");
    }
    
    return 0;
}
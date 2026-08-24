#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) 
    {
        return 0;
    }
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d", current->data);
        if (current->next != NULL) 
        {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
    current = head;
    while (current != NULL) 
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node** tail_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        *tail_ref = new_node;
    } 
    else 
    {
        (*tail_ref)->next = new_node;
        *tail_ref = new_node;
    }
}
void deleteKey(struct Node** head_ref, int key) 
{
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) 
    {
        *head_ref = temp->next; 
        free(temp);            
        return;
    }
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void printList(struct Node* node) 
{
    while (node != NULL) 
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() 
{
    int n, val, key;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        append(&head, &tail, val);
    }
    if (scanf("%d", &key) != 1) return 1;
    deleteKey(&head, key);
    printList(head);
    struct Node* current = head;
    struct Node* next_node;
    while (current != NULL) 
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    
    return 0;
}
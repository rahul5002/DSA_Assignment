#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) 
    {
        last = last->next;
    }
    last->next = new_node;
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
    int n, val;
    struct Node* head = NULL;
    if (scanf("%d", &n) != 1) 
    {
        return 1; 
    }
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        append(&head, val);
    }
    printList(head);
    struct Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
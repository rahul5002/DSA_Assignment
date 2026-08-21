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
struct Node* mergeLists(struct Node* l1, struct Node* l2) 
{
    struct Node dummy;
    dummy.next = NULL;
    struct Node* tail = &dummy;
    while (l1 != NULL && l2 != NULL) 
    {
        if (l1->data <= l2->data) 
        {
            tail->next = l1;
            l1 = l1->next;
        } 
        else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) 
    {
        tail->next = l1;
    } 
    else 
    {
        tail->next = l2;
    }
    return dummy.next;
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
    int n, m, val;
    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;
    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        append(&head1, &tail1, val);
    }
    if (scanf("%d", &m) != 1) return 1;
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &val);
        append(&head2, &tail2, val);
    }
    struct Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);
    struct Node* temp;
    while (mergedHead != NULL) 
    {
        temp = mergedHead;
        mergedHead = mergedHead->next;
        free(temp);
    }
    
    return 0;
}
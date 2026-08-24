#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int size) 
{
    if (size <= 0) 
    {
        return NULL;
    }
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < size; i++) 
    {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void freeList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}
int main() 
{
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* headA = createList(n);
    if (scanf("%d", &m) != 1) 
    {
        freeList(headA);
        return 0;
    }
    struct Node* headB = createList(m);
    struct Node* ptrA = headA;
    struct Node* ptrB = headB;
    int diff = 0;
    if (n > m) 
    {
        diff = n - m;
        for (int i = 0; i < diff; i++) 
        {
            ptrA = ptrA->next;
        }
    } 
    else 
    {
        diff = m - n;
        for (int i = 0; i < diff; i++) 
        {
            ptrB = ptrB->next;
        }
    }
    int found = 0;
    while (ptrA != NULL && ptrB != NULL) 
    {
        if (ptrA->data == ptrB->data) 
        {
            printf("%d\n", ptrA->data);
            found = 1;
            break;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    if (!found) 
    {
        printf("No Intersection\n");
    }
    freeList(headA);
    freeList(headB);

    return 0;
}
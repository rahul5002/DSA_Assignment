#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() 
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        return 0; 
    }
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
            newNode->next = head; 
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
    }
    if (head != NULL) 
    {
        struct Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
    if (head != NULL) 
    {
        struct Node* temp = head;
        struct Node* nextNode;
        do {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } while (temp != head);
    }
    
    return 0;
}
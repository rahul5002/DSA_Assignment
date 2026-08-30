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
    int n, k;
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
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (scanf("%d", &k) != 1) 
    {
        return 0;
    }
    k = k % n;
    if (k > 0) 
    {
        tail->next = head;
        int stepsToNewTail = n - k;
        struct Node* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) 
        {
            newTail = newTail->next;
        }
        head = newTail->next;
        newTail->next = NULL;
    }
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp = head;
    while (temp != NULL) 
    {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    
    return 0;
}
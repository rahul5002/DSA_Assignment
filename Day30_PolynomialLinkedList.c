#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
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
        int c, e;
        scanf("%d %d", &c, &e);
        struct Node* newNode = createNode(c, e);
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
    struct Node* temp = head;
    while (temp != NULL) 
    {
        if (temp->exp == 0) 
        {
            printf("%d", temp->coeff);
        } 
        else if (temp->exp == 1) 
        {
            printf("%dx", temp->coeff);
        } 
        else 
        {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        if (temp->next != NULL) 
        {
            printf(" + ");
        }
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
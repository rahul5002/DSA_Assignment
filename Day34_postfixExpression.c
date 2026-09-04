#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void push(Node** top, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top)
{
    if (*top == NULL)
    {
        return 0;
    }
    
    Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    
    return val;
}

int evaluatePostfix(char* exp)
{
    Node* stack = NULL;
    char* token = strtok(exp, " \t\n");
    
    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            push(&stack, atoi(token));
        }
        else
        {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            
            if (token[0] == '+')
            {
                push(&stack, val2 + val1);
            }
            else if (token[0] == '-')
            {
                push(&stack, val2 - val1);
            }
            else if (token[0] == '*')
            {
                push(&stack, val2 * val1);
            }
            else if (token[0] == '/')
            {
                push(&stack, val2 / val1);
            }
        }
        
        token = strtok(NULL, " \t\n");
    }
    
    return pop(&stack);
}

int main()
{
    char exp[1024];
    
    if (fgets(exp, sizeof(exp), stdin) != NULL)
    {
        printf("%d\n", evaluatePostfix(exp));
    }
    
    return 0;
}
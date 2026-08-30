#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000 

int main() 
{
    int stack[MAX_SIZE];
    int top = -1;
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        return 0;
    }
    for (int i = 0; i < n; i++) 
    {
        int operation;
        scanf("%d", &operation);
        if (operation == 1) 
        {
            int val;
            scanf("%d", &val);
            if (top >= MAX_SIZE - 1) 
            {
                printf("Stack Overflow\n");
            } 
            else 
            {
                stack[++top] = val;
            }
        } 
        else if (operation == 2) 
        {
            if (top == -1) 
            {
                printf("Stack Underflow\n");
            } 
            else 
            {
                printf("%d\n", stack[top]);
                top--;
            }
        } 
        else if (operation == 3) 
        {
            if (top == -1) 
            {
                printf("\n"); 
            } 
            else 
            {
                for (int j = top; j >= 0; j--) 
                {
                    printf("%d", stack[j]);
                    if (j > 0) 
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }
    
    return 0;
}
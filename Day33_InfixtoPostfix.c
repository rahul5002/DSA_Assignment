#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 1000

int precedence(char op) 
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; 
}
int isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int main() 
{
    char infix[MAX_SIZE];
    char stack[MAX_SIZE];
    int top = -1;
    if (scanf("%s", infix) != 1) 
    {
        return 0;
    }
    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char ch = infix[i];
        if (isalnum(ch)) 
        {
            printf("%c", ch);
        } 
        else if (ch == '(') 
        {
            stack[++top] = ch;
        } 
        else if (ch == ')') 
        {
            while (top != -1 && stack[top] != '(') 
            {
                printf("%c", stack[top--]);
            }
            if (top != -1) 
            {
                top--; 
            }
        } 
        else if (isOperator(ch)) 
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) 
            {
                if (ch == '^' && stack[top] == '^') 
                {
                    break;
                }
                printf("%c", stack[top--]);
            }
            stack[++top] = ch;
        }
    }
    while (top != -1) 
    {
        printf("%c", stack[top--]);
    }
    printf("\n");
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pq[100005];
int size = 0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val)
{
    pq[size] = val;
    int curr = size;
    size++;
    
    while (curr > 0 && pq[curr] < pq[(curr - 1) / 2])
    {
        swap(&pq[curr], &pq[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

int peek()
{
    if (size == 0)
    {
        return -1;
    }
    
    return pq[0];
}

int deleteElement()
{
    if (size == 0)
    {
        return -1;
    }
    
    int res = pq[0];
    pq[0] = pq[size - 1];
    size--;
    
    int curr = 0;
    
    while (1)
    {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int smallest = curr;
        
        if (left < size && pq[left] < pq[smallest])
        {
            smallest = left;
        }
        
        if (right < size && pq[right] < pq[smallest])
        {
            smallest = right;
        }
        
        if (smallest != curr)
        {
            swap(&pq[curr], &pq[smallest]);
            curr = smallest;
        }
        else
        {
            break;
        }
    }
    
    return res;
}

int main()
{
    int n;
    
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }
    
    char op[20];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0)
        {
            int val;
            scanf("%d", &val);
            insert(val);
        }
        else if (strcmp(op, "delete") == 0)
        {
            printf("%d\n", deleteElement());
        }
        else if (strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
    }
    
    return 0;
}
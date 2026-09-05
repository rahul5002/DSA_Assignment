#include <stdio.h>
#include <stdlib.h>

struct Stack 
{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item) 
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) 
{
    return stack->array[stack->top--];
}
struct Queue 
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(struct Queue* queue) 
{
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int item) 
{
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) 
{
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
void reverseQueue(struct Queue* q) 
{
    struct Stack* s = createStack(q->capacity);
    while (!isQueueEmpty(q)) 
    {
        push(s, dequeue(q));
    }
    while (!isStackEmpty(s)) 
    {
        enqueue(q, pop(s));
    }
    free(s->array);
    free(s);
}
int main() 
{
    int n;
    
    if (scanf("%d", &n) != 1) 
    {
        return 0;
    }
    
    struct Queue* q = createQueue(n);
    for (int i = 0; i < n; i++) 
    {
        int value;
        scanf("%d", &value);
        enqueue(q, value);
    }
    reverseQueue(q);
    while (!isQueueEmpty(q)) 
    {
        printf("%d ", dequeue(q));
    }
    printf("\n");
    free(q->array);
    free(q);
    
    return 0;
}
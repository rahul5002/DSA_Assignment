#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b)
{
    Interval* intA = (Interval*)a;
    Interval* intB = (Interval*)b;

    if (intA->start < intB->start)
    {
        return -1;
    }
    if (intA->start > intB->start)
    {
        return 1;
    }
    return 0;
}

void pushHeap(int* heap, int* size, int val)
{
    heap[*size] = val;
    int curr = *size;
    (*size)++;

    while (curr > 0)
    {
        int parent = (curr - 1) / 2;
        if (heap[curr] < heap[parent])
        {
            int temp = heap[curr];
            heap[curr] = heap[parent];
            heap[parent] = temp;
            curr = parent;
        }
        else
        {
            break;
        }
    }
}

void popHeap(int* heap, int* size)
{
    if (*size <= 0)
    {
        return;
    }

    heap[0] = heap[*size - 1];
    (*size)--;
    int curr = 0;

    while (1)
    {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int smallest = curr;

        if (left < *size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < *size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != curr)
        {
            int temp = heap[curr];
            heap[curr] = heap[smallest];
            heap[smallest] = temp;
            curr = smallest;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    Interval* intervals = (Interval*)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    // Sort meetings by their start times
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // Min-heap to store the end times of ongoing meetings
    int* minHeap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++)
    {
        // If the earliest ending meeting finishes before or when the current meeting starts, free that room
        if (heapSize > 0 && minHeap[0] <= intervals[i].start)
        {
            popHeap(minHeap, &heapSize);
        }

        // Allocate a room for the current meeting by pushing its end time
        pushHeap(minHeap, &heapSize, intervals[i].end);

        // Track the maximum number of rooms used simultaneously
        if (heapSize > maxRooms)
        {
            maxRooms = heapSize;
        }
    }

    printf("%d\n", maxRooms);

    free(intervals);
    free(minHeap);
    return 0;
}
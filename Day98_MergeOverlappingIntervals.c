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

    // Step 1: Sort intervals based on their start times
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    Interval* merged = (Interval*)malloc(n * sizeof(Interval));
    int mergedSize = 0;

    // Step 2: Iterate and merge overlapping intervals
    for (int i = 0; i < n; i++)
    {
        // If the merged list is empty or the current interval does not overlap with the previous, add it
        if (mergedSize == 0 || merged[mergedSize - 1].end < intervals[i].start)
        {
            merged[mergedSize++] = intervals[i];
        }
        else
        {
            // Otherwise, there is an overlap, so update the end time of the previous interval
            if (intervals[i].end > merged[mergedSize - 1].end)
            {
                merged[mergedSize - 1].end = intervals[i].end;
            }
        }
    }

    // Print the resulting merged intervals
    for (int i = 0; i < mergedSize; i++)
    {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    free(intervals);
    free(merged);
    return 0;
}
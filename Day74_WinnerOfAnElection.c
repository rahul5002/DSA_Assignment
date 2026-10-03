#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    return strcmp((const char*)a, (const char*)b);
}

int main()
{
    int n;
    
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }

    char(*arr)[105] = malloc(n * sizeof(*arr));
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(*arr), compare);

    char winner[105];
    strcpy(winner, arr[0]);
    int max_votes = 0;
    int current_votes = 1;

    for (int i = 1; i < n; i++)
    {
        if (strcmp(arr[i], arr[i - 1]) == 0)
        {
            current_votes++;
        }
        else
        {
            if (current_votes > max_votes)
            {
                max_votes = current_votes;
                strcpy(winner, arr[i - 1]);
            }
            current_votes = 1;
        }
    }

    if (current_votes > max_votes)
    {
        max_votes = current_votes;
        strcpy(winner, arr[n - 1]);
    }

    printf("%s %d\n", winner, max_votes);

    free(arr);

    return 0;
}
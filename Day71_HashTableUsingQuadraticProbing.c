#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int m, n;
    
    if (scanf("%d %d", &m, &n) != 2)
    {
        return 0;
    }

    int* table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        table[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0)
        {
            int h = key % m;
            
            for (int j = 0; j < m; j++)
            {
                int pos = (h + j * j) % m;
                
                if (table[pos] == -1 || table[pos] == key)
                {
                    table[pos] = key;
                    break;
                }
            }
        }
        else if (strcmp(op, "SEARCH") == 0)
        {
            int h = key % m;
            bool found = false;
            
            for (int j = 0; j < m; j++)
            {
                int pos = (h + j * j) % m;
                
                if (table[pos] == key)
                {
                    found = true;
                    break;
                }
                
                if (table[pos] == -1)
                {
                    break;
                }
            }
            
            if (found)
            {
                printf("FOUND\n");
            }
            else
            {
                printf("NOT FOUND\n");
            }
        }
    }

    free(table);

    return 0;
}
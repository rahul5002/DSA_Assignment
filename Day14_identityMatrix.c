#include <stdio.h>

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int is_identity = 1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int val;
            scanf("%d", &val);
            if (i == j && val != 1) 
            {
                is_identity = 0;
            } 
            else if (i != j && val != 0) 
            {
                is_identity = 0;
            }
        }
    }
    if (is_identity) 
    {
        printf("Identity Matrix\n");
    } 
    else 
    {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
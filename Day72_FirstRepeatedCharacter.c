#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char s[100005];
    
    if (scanf("%s", s) != 1)
    {
        return 0;
    }

    bool seen[26] = { false };
    char ans = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int idx = s[i] - 'a';
        
        if (seen[idx])
        {
            ans = s[i];
            break;
        }
        
        seen[idx] = true;
    }

    if (ans != -1)
    {
        printf("%c\n", ans);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
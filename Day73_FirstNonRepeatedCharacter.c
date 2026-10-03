#include <stdio.h>
#include <string.h>

int main()
{
    char s[100005];
    
    if (scanf("%s", s) != 1)
    {
        return 0;
    }

    int freq[26] = { 0 };
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
    }

    char ans = '$';
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (freq[s[i] - 'a'] == 1)
        {
            ans = s[i];
            break;
        }
    }

    printf("%c\n", ans);

    return 0;
}
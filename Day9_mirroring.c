#include <stdio.h>
#include <string.h>

void mirrorStringHelper(char* str, int start, int end) 
{
    if (start >= end) 
    {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;    
    mirrorStringHelper(str, start + 1, end - 1);
}
void mirrorString(char* str) 
{
    int length = strlen(str);
    if (length > 0) 
    {
        mirrorStringHelper(str, 0, length - 1);
    }
}
int main() 
{
    char codename[100001]; 
    if (scanf("%100000s", codename) == 1) 
    {
        mirrorString(codename);
        printf("%s\n", codename);
    }
    
    return 0;
}
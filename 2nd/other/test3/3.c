#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *s, int numRows)
{
    if (s == NULL || strlen(s) <= 0)
        return NULL;

    char s1[100][20];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            s1[i][j] = 0;
        }
    }
    int rawLen = strlen(s);
    int times = 0;
    for (int i = 0, j = 0; *(s + times) != '\0' && j < 20;)
    {
        if (i == 0)
        {
            while (i < numRows && times < rawLen)
            {
                s1[i++][j] = *(s + times); // z
                times++;
            }
            i -= 1;
        }
        if (i == numRows - 1)
        {
            while (i > 1 && times < rawLen)
            {
                s1[--i][++j] = *(s + times); ///
                times++;
            }
            --i;
            ++j;
        }
    }

    int len = sizeof(char) * (strlen(s) + 1);
    char *s2 = (char *)malloc(len);
    if (s2 == NULL)
        return NULL;

    memset(s2, 0x0, len);
    
    int k = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (s1[i][j] != 0)
            {
                s2[k] = s1[i][j];
                k++;
            }
        }
    }
    s2[k] = '\0';
    return s2;
}

int main()
{
    char s[30] = {0};
    fgets(s, 30 - 1, stdin); //

    char *s0 = convert(s, 3);
    for (int i = 0; i < strlen(s0); i++)
    {
        printf("%c[%d] ", s0[i], s0[i]);
    }
    free(s0);
    return 0;
}
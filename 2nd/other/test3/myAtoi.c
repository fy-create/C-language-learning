#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myAtoi(char *s)
{
    int num = 0;
    int num1 = 0;
    char s1[201]; // 0 <= s.length <= 200
    int flag = 1;
    if (s[0] == ' ')
    {
        for (num = 0; s[num] == ' '; num++)
            ;
    }
    if (s[num] == '+')
        num++;
    else if (s[num] == '-')
    {
        num++;
        flag = -1;
    }
    while (s[num] >= '0' && s[num] <= '9')
    {
        s1[num1++] = s[num++];
    }
    s1[num1] = '\0';
    int res = 0;
    long long checkBound = 0;//我用升位法，long long 是64位数字，比int要大

    for (int i = 0; s1[i] != '\0'; i++)
    {
        checkBound = checkBound * 10 + (s1[i] - '0') * flag;
        if (checkBound <= INT_MIN)      //这个C库有定义 #define INT_MIN     (-2147483647 - 1)
        {
            res = INT_MIN;
            break;
        }
        else if (checkBound >= INT_MAX) //这个C库有定义 #define INT_MAX       2147483647
        {
            res = INT_MAX;
            break;
        }
        else
        {
            res = (int)(checkBound);
        }
    }

    return res;
}


int main() {
    char source[] = "-91283472332";
    int res = myAtoi(source);

    printf("res=%d\n", res);
    getchar();

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int cnt = 0;

void backtrack(char *digits, int index, char *combination, char **ret);

char **letterCombinations(char *digits, int *returnSize)
{
    char **ret = (char **)malloc(sizeof(char *) * 1000);
    char combination[10] = {0};
    backtrack(digits, 0, combination, ret);
    *returnSize = cnt;

    return ret;
}
void backtrack(char *digits, int index, char *combination, char **ret)
{

    if (index == strlen(digits))
    {
        ret[cnt] = (char *)malloc((strlen(combination) + 1) * sizeof(char));
        strcpy(ret[cnt++], combination);
        return;
    }
    const char *letter = s[digits[index] - '0'];
    for (int i = 0; i < strlen(letter); i++)
    {
        combination[index] = letter[i];

        backtrack(digits, index + 1, combination, ret);
    }
}

int main()
{
    char digits[] = "23";
    int size = 0;
    char **combinations = letterCombinations(digits, &size);

    // 输出结果
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", combinations[i]);
        free(combinations[i]); // 释放每个字符串的内存
    }
    free(combinations); // 释放结果数组的内存

    printf("size=%d\n", size);

    return 0;
}
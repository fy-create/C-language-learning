#include <stdio.h>
#include <string.h>
int main()
{
    char strings[100][21];
    int max_len = 0;
    while (1)
    {
        fgets(strings[max_len], 21, stdin);
        max_len++;
        if (strlen(strings[max_len - 1]) == 5)
            break;
    }

    // 假设第一个字符串是最大和最小的
    char *maxStr = strings[0];
    char *minStr = strings[0];

    // 遍历字符串数组，比较找到最大和最小的字符串
    for (int i = 1; i < max_len; i++)
    {
        if (strcmp(strings[i], maxStr) > 0)
        { // 当前字符串大于 maxStr
            maxStr = strings[i];
        }
        if (strcmp(strings[i], minStr) < 0)
        { // 当前字符串小于 minStr
            minStr = strings[i];
        }
    }

    // 输出最大和最小字符串
    printf("Smallest string: %s\n", minStr);
    printf("Largest string: %s\n", maxStr);

    return 0;
}

// 最大最小单词简略版（The Biggest and Smallest Words）
// 编写程序找出一组单词中“最小”单词和“最大”单词。
// 用户输入单词后，程序根据字典顺序决定排在最前面和最后面的单词。
// 当用户输入4个字母的单词时，程序停止读入。假设所有单词都不超过20个字母。

// 看题意是要找到最大最小的字符串，其实就是找到2个指向最大最小的index,
// 可以定义min max 这2个index,一开始都等于0，就是第0个字符串，
// 然后一轮遍历比较就能找到这2个index,而且还不会改变原有的输入序列。

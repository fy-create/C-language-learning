#include <stdio.h>
#include <string.h>

// 辅助函数：从指定中心扩展
int expandAroundCenter(const char *s, int left, int right)
{
    while (left >= 0 && right < strlen(s) && s[left] == s[right])
    {
        left--;
        right++;
    }
    // 返回回文的长度
    return right - left - 1;
}

// 主函数：找到最长回文子串
char *longestPalindrome(char *s)
{
    int n = strlen(s);
    if (n < 1)
        return NULL;

    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        // 以单个字符为中心扩展（奇数长度回文）
        int len1 = expandAroundCenter(s, i, i);
        // 以两个字符间隙为中心扩展（偶数长度回文）
        int len2 = expandAroundCenter(s, i, i + 1);
        // 获取两种扩展方式中较长的回文
        int len = (len1 > len2) ? len1 : len2;

        // 更新最长回文的起点和终点
        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    // 提取最长回文子串
    static char result[1000]; // 假设结果不会超过 1000 长度
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';
    return result;
}

// 测试
int main()
{
    char s[] = "babadddaa";
    printf("Longest Palindromic Substring: %s\n", longestPalindrome(s));
    return 0;
}

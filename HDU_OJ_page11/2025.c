#include <stdio.h>

// 对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。
// http://acm.hdu.edu.cn/showproblem.php?pid=2025

int main() {
    char str[150];
    while (scanf("%s%*c", str) != EOF) {
        int count = 0;
        char maxChar = str[0];
        char *pCh = str;
        while (*pCh != '\0') { // 遍历一次计算最大元素，和最大元素出现的次数
            if (*pCh > maxChar) {
                count = 1;
                maxChar = *pCh;
            } else if (*pCh == maxChar) {
                count++;
            }
            pCh++;
        }
        int newLength = count * 5 + (int) (pCh - str); // 由愿字符串长度和最大元素出现的次数可以计算出添加字符后新的字符串长度
        str[newLength] = '\0';
        for (int i = newLength - 1; i >= 0; --i) { // 从后往前遍历，依次移动每一个字符
            if (str[i - count * 5] == maxChar) { // 添加字符
                str[i--] = ')';
                str[i--] = 'x';
                str[i--] = 'a';
                str[i--] = 'm';
                str[i--] = '(';
                count--;
            }
            str[i] = str[i - count * 5];
            if (count == 0) { // 所有需要添加的字符都已添加完，可以结束循环
                break;
            }
        }
        printf("%s\n", str);
    }

    return 0;
}
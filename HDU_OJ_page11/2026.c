#include <stdio.h>

// 输入一个英文句子，将每个单词的第一个字母改成大写字母。
// http://acm.hdu.edu.cn/showproblem.php?pid=2026

int main() {
    char str[100];
    while (scanf("%[^\n]%*c", str) != EOF) {
        char *pCh = str;
        while (*pCh != '\0') {
            if (pCh == str && *pCh >= 'a' && *pCh <= 'z') {
                *pCh = *pCh - 32; // 小写转大写即小写字母的 ASCII 码 -32
            }
            if (*pCh == ' ' && *(pCh + 1) >= 'a' && *(pCh + 1) <= 'z') {
                *(pCh + 1) = *(pCh + 1) - 32;
            }
            pCh++;
        }
        printf("%s\n", str);
    }


    return 0;
}
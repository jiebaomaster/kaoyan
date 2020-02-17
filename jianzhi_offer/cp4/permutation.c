#include <stdio.h>

/**
 * 递归求全排列
 * 1. 将字符串看为两部分，一部分是第一个字符，另一部分是其后所有字符。接下来求第二部分的全排列
 * 2. 将第一个字符与它之后的字符逐个交换
 * @param str
 * @param pBegin
 */
void permutationCore(char *str, char *pBegin) {
    if (*pBegin == '\0') {
        printf("%s\n", str);
        return;
    }
    for (char *p = pBegin; *p != '\0'; ++p) { // 第一个字符与之后的字符逐个交换
        char tmp = *p;
        *p = *pBegin;
        *pBegin = tmp;

        permutationCore(str, pBegin + 1); // 求第二部分的全排列

        // 恢复字符串
        tmp = *p;
        *p = *pBegin;
        *pBegin = tmp;
    }
}

/**
 * P197 求字符串的全排列
 * @param str
 */
void permutation(char *str) {
    if (str == NULL) { return; }
    permutationCore(str, str);
}

int main() {
    char str[] = "abc";
    permutation(str);

    return 0;
}
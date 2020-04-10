/*
 * P286 左旋转字符串，把字符串的前端若干个位的字符转移到字符串尾部
 */

#include <stdio.h>
#include <string.h>

/**
 * 首尾指针法，翻转字符串
 * @param pBegin
 * @param pEnd
 */
void reverse(char *pBegin, char *pEnd) {
    if (pBegin == NULL || pEnd == NULL) { return; }

    while (pBegin < pEnd) {
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;

        // 进行一次交换之后，将指针向中间移动
        pBegin++;
        pEnd--;
    }
}

/**
 * 左旋转字符串
 * 将字符串按旋转区间分成两部分，先整体翻转，再分别翻转两部分
 * @param str
 * @param k
 */
void leftRotateString(char str[], int k) {
    if (str == NULL || k <= 0) { return; }
    int length = strlen(str);
    if (length <= k) { return; }

    reverse(str, str + length - 1); // 整体翻转一次
    // 两部分分别翻转
    reverse(str, str + length - k - 1);
    reverse(str + length - k, str + length - 1);
}

int main() {
    char testStr[] = "abcdefg";
    leftRotateString(testStr, 2);
    printf("%s", testStr);

    return 0;
}


/*
 * P284 翻转英文句子中的单词顺序，标点符号看作普通字母
 * 先把句子整体翻转，此时句子中单词逆序，单词的字母也逆序，再将每个单词翻转
 */

#include <stdio.h>

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

void reverseSentence(char str[]) {
    if (str == NULL) { return; }

    char *pBegin = str;
    char *pEnd = pBegin;
    while (*pEnd != '\0') { pEnd++; }
    pEnd--;

    reverse(pBegin, pEnd); // 翻转整个句子

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') { // 英文句子以空格分割单词，则扫描到一个空格就可以确定一个单词的边界
            pEnd = str + i - 1;
            reverse(pBegin, pEnd); // 翻转每个单词
            pBegin = pEnd + 2;
        }
        i++;
    }
    reverse(pBegin, str + i - 1); // 最后一个单词的末尾没有空格，单独处理
}

int main() {
    char testStr[] = "I am a student.";
    reverseSentence(testStr);
    printf("%s", testStr);

    return 0;
}

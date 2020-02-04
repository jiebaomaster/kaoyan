#include <stdio.h>

/*
 * P51 替换字符串中的空格
 * 倒序便利字符串
 */

void replaceSpace(char str[], int length) {
    // 遍历一次字符串计算共有几个空格
    int count = 0;
    int realLength = 0;
    while (str[realLength] != '\0') {
        if (str[realLength] == ' ') { count++; }
        realLength++;
    }
    // 替换空格后超出字符串可用长度，不进行替换直接退出
    if (realLength + count * 2 > length) {
        return;
    }

    // 单指针 count 计数法
    for (int i = realLength - 1; count > 0; --i) {
        if (str[i] == ' ') {
            str[i + 2 * count] = '0';
            str[i + 2 * count - 1] = '2';
            str[i + 2 * count - 2] = '%';
            count--;
        } else {
            str[i + 2 * count] = str[i];
        }
    }
}

void replaceSpace2(char str[], int length) {
    // 遍历一次字符串计算共有几个空格
    int count = 0;
    int realLength = 0;
    while (str[realLength] != '\0') {
        if (str[realLength] == ' ') { count++; }
        realLength++;
    }
    // 替换空格后超出字符串可用长度，不进行替换直接退出
    int newLength = realLength + count * 2;
    if (newLength > length) {
        return;
    }

    // 本地快慢双指针法遍历，慢指针追上快指针时退出
    newLength--;
    for (int i = realLength - 1; i < newLength; --i) {
        if (str[i] == ' ') {
            str[newLength--] = '0';
            str[newLength--] = '2';
            str[newLength--] = '%';
        } else {
            str[newLength--] = str[i];
        }
    }
}


int main() {
    char testStr[30] = " we are happy!   ";
    replaceSpace(testStr, 29);
    char testStr2[30] = " we are happy!   ";
    replaceSpace2(testStr2, 29);

    printf("1：%s\n2: %s", testStr, testStr2);
}
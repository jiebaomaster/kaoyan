#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// P114 打印从 1 到最大的 n 位数

/**
 * 字符串表示的数字的自增
 * @param number 字符串数字
 * @param n 位数
 * @return 自增成功返回 true，否则返回 false
 */
bool increment(char *number, int n) {
    int takeover = 0; // 低位进位
    bool isOverflow = false; // 是否溢出
    for (int i = n - 1; i >= 0; --i) { // 从最低位开始计算
        int nSum = number[i] - '0' + takeover; // 当前位的值, number[i] - '0'这里将 char 转化为 int
        if (i == n - 1) { nSum++; } // 最低位加一，即数字自增1
        if (nSum >= 10) { // 本位计算结果比十大，需进位
            if (i == 0) { // 最高位产生进位，发生溢出，自增结束
                isOverflow = true;
            } else {
                takeover = 1;
                number[i] = '0';
            }
        } else { // 本位未产生进位，则计算到此为止
            number[i] = nSum + '0'; // 等式左边转化为 ascii 码计算，最后用一个 char 类型存储 ascii 码代表的字符
            break;
        }
    }
    return isOverflow;
}

/**
 * 打印字符串表示的数字，例："00011"打印为"11"
 * @param n 位数
 */
void printStringNumber(char *number) {
    bool hasPassZero = false;
    for (int i = 0; number[i] != '\0'; ++i) {
        if (!hasPassZero && number[i] != '0') {
            hasPassZero = true;
        }
        if (hasPassZero) {
            printf("%c", number[i]);
        }
    }
    printf("\n");
}

/**
 * 依次打印从 1 到最大的 n 位数
 * 考虑大数问题，最大的n位数可能非常大，超出所有数据类型的表示范围，故这里用字符串模拟数字
 * @param n
 */
void print1ToMaxOfDigits(int n) {
    if (n <= 0) { return; }

    // 初始化字符串代表数字，例：n=5 时，"00000\0"
    char *number = (char *) malloc(n + 1);
    for (int i = 0; i < n; ++i) {
        number[i] = '0';
    }
    number[n] = '\0';

    while (!increment(number, n)) {
        printStringNumber(number);
    }
}


int main() {
    print1ToMaxOfDigits(3);

    return 0;
}
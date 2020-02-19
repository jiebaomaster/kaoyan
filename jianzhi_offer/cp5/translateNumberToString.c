#include <stdio.h>

/**
 * P231 把数字翻译成字符串，求有几种翻译方式
 * 翻译规则：从左到右，0->a, 1->b, 2->c, ..., 25->z
 * f(i) 表示从这个数第 i 位开始的数字的翻译方式数，则
 * f(i) = { f(i+1) + f(i+2) ,第 i 位和 i+1 位拼接成的数字 k，有 10<=k<=25
 *        { f(i+1)          ,其他
 * @param number
 * @return
 */
int translateNumberToString(int number) {
    int fi = 1; // f(i+1)
    int fii = 1; // f(i+2)

    while (number / 10) { // 从后往前遍历每一位
        int iwithii = number % 100; // 最后两位即第 i 位和 i+1 位拼接成的数字 k
        if (iwithii <= 25 && iwithii >= 10) {
            int tmp = fi + fii;
            fii = fi;
            fi = tmp;
        } else {
            fii = fi;
        }
        number /= 10;
    }
    return fi;
}

int main() {
    int number = 12258;
    printf("%d", translateNumberToString(number));

    return 0;
}
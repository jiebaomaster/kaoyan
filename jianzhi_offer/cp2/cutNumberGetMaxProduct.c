#include <stdio.h>

/**
 * P96 将一条长度为n的绳子剪若干刀，使得每一段的长度之积最大，求最大积
 * 动态规划
 * @param length
 * @return
 */
int findMaxProductCutting(int length) {
    if (length < 2) { return 0; }
    else if (length == 2) { return 1; }
    else if (length == 3) { return 2; }

    int products[length + 1]; // 长度为i的绳子，一刀不剪或者剪n刀的乘积最大值数组
    products[0] = 0;
    products[1] = 1;
    int max = 0;
    for (int i = 2; i < length + 1; ++i) {
        max = i; // max初始化为一刀不剪的状态
        for (int j = 1; j <= i / 2; ++j) { // f(n) = max{ f(j) * f(n-j) }
            int product = products[j] * products[i - j];
            max = max < product ? product : max;
        }
        products[i] = max;
    }
    return products[length];
}

int main() {
    printf("%d", findMaxProductCutting(16));
    return 0;
}
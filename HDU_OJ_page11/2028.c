#include <stdio.h>
#include <stdlib.h>

// 求n个数的最小公倍数。
// http://acm.hdu.edu.cn/showproblem.php?pid=2028

/**
 * 辗转相除法计算最大公约数
 * https://baike.baidu.com/item/%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95/1647675?fromtitle=%E8%BE%97%E8%BD%AC%E7%9B%B8%E9%99%A4%E6%B3%95&fromid=4625352
 * @param n
 * @param m
 * @return
 */
int getGreatestCommonDivisor(int n, int m) {
    int tmp;
    while (m > 0) {
        tmp = m;
        m = n % m;
        n = tmp;
    }
    return n;
}

/**
 * 求最大公倍数
 * @param n
 * @param m
 * @return
 */
int getLowestCommonMultiplePlus(int n, int m) {
    // 最大公倍数 = n * m / 最大公约数，先除再乘防止溢出
    return n / getGreatestCommonDivisor(n, m) * m;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int *data = (int *) malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", data + i);
        }
        int result = *data;
        for (int i = 1; i < n; ++i) { // 依次求最小公倍数
            result = getLowestCommonMultiplePlus(*(data + i), result);
        }
        printf("%d\n", result);
        free(data);
    }
}
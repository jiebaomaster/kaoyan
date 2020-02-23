#include <stdio.h>
#include <stdbool.h>

// “水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。
// 现在要求输出所有在 m 和 n 范围内的水仙花数。
// http://acm.hdu.edu.cn/showproblem.php?pid=2010

/**
 * 判断一个数字是否是水仙花数
 * @param number
 * @return
 */
bool isTheNumber(int number) {
    int tmp = number;
    int sum = 0;
    while (tmp) {
        sum += (tmp % 10) * (tmp % 10) * (tmp % 10);
        tmp = tmp / 10;
    }
    return sum == number;
}

int main() {
    int m, n, tmp;
    while (scanf("%d %d", &m, &n) != EOF) {
        if (m > n) tmp = m, m = n, n = tmp;
        bool hasTheNumber = false;
        for (int i = m; i <= n; ++i) {
            if (isTheNumber(i)) {
                if (hasTheNumber) { // 用一个标志，第一个数字前不输出空格，之后的数字前面输出一个空格，解决间隔空格输出问题
                    printf(" ");
                }
                printf("%d", i);
                hasTheNumber = true;
            }
        }
        if (!hasTheNumber) printf("no\n");
        else printf("\n");
    }
    return 0;
}

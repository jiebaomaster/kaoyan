#include <stdio.h>

// 求 n 的 m 次方，请输出 A^B 的最后三位表示的整数
// http://acm.hdu.edu.cn/showproblem.php?pid=2035


int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        if (a == 0 && b == 0) { break; }
        int base = a;
        int result = 1;
        while (b) { // 简单快速幂的循环写法，由于只需要结果的最后三位，则每次计算都只用保留最后三位
            if (b % 2) {
                result = result * base % 1000;
            }
            base = base * base % 1000;
            b /= 2;
        }
        printf("%d\n", result);
    }

    return 0;
}
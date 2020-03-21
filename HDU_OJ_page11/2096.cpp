/*
 * 简单截断求和
 * http://acm.hdu.edu.cn/showproblem.php?pid=2096
 */

#include <cstdio>

int main() {
    int n;
    int a, b;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &b);
            a %= 100;
            b %= 100;
            printf("%d\n", (a + b) % 100);
        }
    }

    return 0;
}
#include <stdio.h>

// 有一楼梯共 M 级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第 M 级，共有多少种走法？
// 简单动态规划，fibo 数列变式
// http://acm.hdu.edu.cn/showproblem.php?pid=2041

int main() {
    int n;
    int m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &m);
            int step1 = 1;
            int step2 = 1;
            int tmp;
            while (m-- - 2 > 0) {
                tmp = step2;
                step2 = step1 + step2;
                step1 = tmp;
            }
            printf("%d\n", step2);
        }
    }
    return 0;
}

#include <stdio.h>

// 求下列多项式的前 n 项和：
// 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
// http://acm.hdu.edu.cn/showproblem.php?pid=2011

int main() {
    int m, n;
    double sum;
    double isMinus; // 记录交错级数的正负号
    while (scanf("%d", &m) != EOF) {
        for (int i = 0; i < m; ++i) {
            scanf("%d", &n);
            // 下一次计算前要重置
            sum = 0;
            isMinus = 1;
            for (int j = 1; j <= n; ++j) {
                sum += isMinus / j;
                isMinus *= -1;
            }
            printf("%.2lf\n", sum);
        }
    }
}
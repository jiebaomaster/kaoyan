#include <stdio.h>

// 判断一个三个数是否能组成三角形
// http://acm.hdu.edu.cn/showproblem.php?pid=2039

int main() {
    int n;
    double edge[3]; // 边长有可能是浮点数
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", edge, edge + 1, edge + 2);
            if (edge[0] <= edge[2] - edge[1]
                || edge[0] + edge[2] <= edge[1]
                || edge[1] + edge[2] <= edge[0]) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        }
    }
}
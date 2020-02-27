#include <stdio.h>

// 求 n 条折线分割平面的最大数目。比如，一条折线可以将平面分成两部分，两条折线最多可以将平面分成7部分
// 平面分割问题，关键在于分析每次添加新增的线段与新增区域的关系
// https://blog.csdn.net/achesong/article/details/87435669
// http://acm.hdu.edu.cn/showproblem.php?pid=2050

int main() {
    long long an[10010] = {0, 2};
    for (int j = 2; j < 10010; ++j) {
        an[j] = an[j - 1] + 4 * (j - 1) + 1;
    }
    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &m);
            printf("%lld\n", an[m]);
        }
    }
}
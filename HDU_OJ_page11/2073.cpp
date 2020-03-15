/*
 * 按特殊路径计算两点间的距离
 * http://acm.hdu.edu.cn/showproblem.php?pid=2073
 */
#include <cstdio>
#include <cmath>

using namespace std;

/**
 * 计算一点到 0 点的距离
 * @param x
 * @param y
 * @return
 */
double calPathLengthForm0(int x, int y) {
    int k = x + y; // 任意点都在斜线 x+y=k 上
    double ans = 0;
    for (int i = 0; i < k; ++i) { // 计算斜线的连接线的长度
        ans += sqrt(i * i + (i + 1) * (i + 1));
    }
    ans += (1.0 * (k - 1) * k / 2 + x) * sqrt(2); // 斜率为 -1 的斜线长度和最后一段部分斜线长
    return ans;
}

/*
 * input:
 * 5
 * 0 0 0 1
 * 0 0 1 0
 * 2 3 3 1
 * 99 99 9 9
 * 5 5 5 5
 * output:
 * 1.000
 * 2.414
 * 10.646
 * 54985.047
 * 0.000
 */
int main() {
    int n;
    int x1, y1, x2, y2;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            // 两点之间的距离为两点到 0 点距离之差的绝对值
            printf("%.3lf\n", abs(calPathLengthForm0(x1, y1) - calPathLengthForm0(x2, y2)));
        }
    }
    return 0;
}
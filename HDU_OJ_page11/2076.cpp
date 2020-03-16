/*
 * 计算钟表上时针与分针的夹角大小
 * http://acm.hdu.edu.cn/showproblem.php?pid=2076
 *
 * input:
 * 2
 * 8 3 17
 * 5 13 30
 * output:
 * 138
 * 75
 */

#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n;
    int h, m, s;
    double hh, mm;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &h, &m, &s);
            if (h >= 12) { h -= 12; }
            mm = m * 6 + 1.0 * s / 10; // 分针与 0 的夹角
            hh = h * 30 + 1.0 * m / 2 + 1.0 * s / 120; // 时针与 0 的夹角
            double ans = abs(mm - hh);
            if (ans > 180) { ans = 360 - ans; } // 夹角大于 180 的求其补角
            printf("%d\n", (int) ans);
        }
    }
}
/*
 * 解方程：x + y = n，x * y = m
 * http://acm.hdu.edu.cn/showproblem.php?pid=2092
 *
 * intput:
 * 9 15
 * 5 4
 * 1 -56
 * output:
 * No
 * Yes
 * Yes
 */

#include <cstdio>
#include <cmath>

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (!n && !m) { break; }
        double delt = n * n - 4 * m;
        if (delt < 0) {
            printf("No\n");
            continue;
        }
        double x = (n + sqrt(delt)) / 2;
        double y = (n - sqrt(delt)) / 2;
        if (x == (int) x || y == (int) y) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
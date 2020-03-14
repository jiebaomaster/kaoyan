/*
 * find max
 * http://acm.hdu.edu.cn/showproblem.php?pid=2071
 */

#include <cstdio>

/*
 * input:
 * 2
 * 3 170.00 165.00 180.00
 * 4 165.00 182.00 172.00 160.00
 * output:
 * 180.00
 * 182.00
 */
int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &m);
            double tmp, max = -1;
            for (int j = 0; j < m; ++j) {
                scanf("%lf", &tmp);
                if (j == 0 || max < tmp) { max = tmp; }
            }
            printf("%.2lf\n",max);
        }
    }
}
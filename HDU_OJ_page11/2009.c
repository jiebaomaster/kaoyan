#include <stdio.h>
#include <math.h>

// 数列的第一项为 n，以后各项为前一项的平方根，求数列的前 m 项的和。
// http://acm.hdu.edu.cn/showproblem.php?pid=2009

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        double sum = n;
        double tmp = n;
        for (int i = 0; i < m - 1; ++i) {
            tmp = sqrt(tmp);
            sum += tmp;
        }
        printf("%.2lf\n", sum);
    }
}
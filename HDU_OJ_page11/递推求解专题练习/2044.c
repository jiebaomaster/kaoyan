#include <stdio.h>

// 有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房 a 爬到蜂房 b 的可能路线数。
// 其中，蜂房的结构如下所示。
// 1 -> 3 -> 5 -> 7 -> 9 -> ...
//   2 -> 4 -> 6 -> 8 -> 10 -> ...
// 与跳台阶问题相似，fibo 数列的变式，⚠️本题中 0<a<b<50，要用长整型 long long
// http://acm.hdu.edu.cn/showproblem.php?pid=2044

int main() {
    int n;
    int a, b;
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            scanf("%d %d", &a, &b);
            int dif = b - a;
            if (dif < 0) {
                dif = -dif;
            }
            long long f1 = 1;
            long long f2 = 1;
            long long tmp;
            while (--dif) {
                tmp = f2;
                f2 = f1 + f2;
                f1 = tmp;
            }
            printf("%lld\n", f2);
        }
    }
}
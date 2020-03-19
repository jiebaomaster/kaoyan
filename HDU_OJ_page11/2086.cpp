/*
 * 有如下方程：Ai = (Ai-1 + Ai+1)/2 - Ci (i = 1, 2, 3, .... n).若给出A0, An+1, 和 C1, C2, .....Cn.请编程计算A1 = ?
 * http://acm.hdu.edu.cn/showproblem.php?pid=2086
 * 数学推导过程如下：
 *   因为：Ai=(Ai-1+Ai+1)/2 - Ci,
 *        A1=(A0  +A2  )/2 - C1;
 *        A2=(A1  +  A3)/2 - C2 , ...
 *   =>   A1+A2 = (A0+A2+A1+A3)/2 - (C1+C2)
 *   =>   A1+A2 =  A0+A3 - 2(C1+C2)
 *   同理可得：
 *        A1+A1 =  A0+A2 - 2(C1)
 *        A1+A2 =  A0+A3 - 2(C1+C2)
 *        A1+A3 =  A0+A4 - 2(C1+C2+C3)
 *        A1+A4 =  A0+A5 - 2(C1+C2+C3+C4)
 *        ...
 *        A1+An = A0+An+1 - 2(C1+C2+...+Cn)
 *    ---------- 左右求和 --------------
 *        (n+1)A1+(A2+A3+...+An) = nA0 +(A2+A3+...+An) + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)
 *   =>   (n+1)A1 = nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)
 *   =>   A1 = [nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)]/(n+1)
 *
 * input:
 * 1
 * 50.00
 * 25.00
 * 10.00
 * 2
 * 50.00
 * 25.00
 * 10.00
 * 20.00
 * output:
 * 27.50
 * 15.00
 */

#include <cstdio>

double c[3010];

int main() {
    int n;
    double a0, an_1;
    while (scanf("%d", &n) != EOF) {
        scanf("%lf%lf", &a0, &an_1);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf", &c[i]);
        }

        double ans = n * a0 + an_1;
        for (int j = 1; j <= n; ++j) {
            ans -= 2 * c[j] * (n - j + 1);
        }
        ans /= n + 1;
        printf("%.2lf\n", ans);
    }

    return 0;
}
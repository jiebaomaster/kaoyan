#include <stdio.h>

// 有排成一行的 ｎ(0<n<=50) 个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，
// 每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法.
// f(i) 是 i 个格子的涂法数，考虑在 i-1 个格子后添加一个格子：
// 1. 由于 1 和 i-1 的格子颜色必不相同，则 i 格只能选择一种颜色，即 f(i-1)
// 2. 由于添加了 i 格之后，i-1 格不再是最后一格，故其颜色可以与 1 格相同，此时前 i-1 格共有 f(i-2) 种涂法，且i格可选两种颜色，即 f(i-2)*2
// 综上，f(i) = f(i-1) + f(i-2) * 2
// 注意 i=3 的情况，此时 i-1=2，与 1 格相邻颜色不能相同，故 f(3)=f(3-1)=6
// http://acm.hdu.edu.cn/showproblem.php?pid=2045

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 1) {
            printf("3\n");
        } else if (n == 2) {
            printf("6\n");
        } else {
            n -= 3;
            long long f1 = 6;
            long long f2 = 6;
            long long tmp;
            while (n--) {
                tmp = f2;
                f2 = f1 * 2 + f2;
                f1 = tmp;
            }
            printf("%lld\n", f2);
        }
    }
}
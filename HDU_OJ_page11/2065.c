/*
 * 现在有一长度为N的字符串,满足一下条件:
 * (1) 字符串仅由A,B,C,D四个字母组成;
 * (2) A出现偶数次(也可以不出现);
 * (3) C出现偶数次(也可以不出现);
 * 计算满足条件的字符串个数.
 * 当N=2时,所有满足条件的字符串有如下6个:BB,BD,DB,DD,AA,CC. 由于这个数据肯能非常庞大,你只要给出最后两位数字即可.
 *
 * f[n][0]保存长度为n，合法的字符串的个数。
 * f[n][1]保存长度为n，仅A出现奇数次的字符串的个数。
 * f[n][2]保存长度为n，仅C出现奇数次的字符串的个数。
 * f[n][3]保存长度为n，A、C出现奇数次的字符串的个数。
 *
 * 长度为n-1的合法字符串在末尾加上一个B或者D，都可以变成长度为n的合法字符串。
 * 长度为n-1的仅A出现奇数次的字符串再在末尾加上一个A，也可以变成合法字符串。
 * 长度为n-1的仅C出现奇数次的字符串再在末尾加上一个C，也可以变成合法字符串。
 * 所以，f[n][0] = 2 × f[n-1][0] + f[n-1][1] + f[n-1][2];
 * https://blog.csdn.net/wongson/article/details/4029863?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
 * http://acm.hdu.edu.cn/showproblem.php?pid=2065
 */

#include <stdio.h>

int main(void) {
    long long n;
    int c, t;
    int d[] = {
            4, 8, 16, 32, 64, 28, 56, 12, 24, 48,
            96, 92, 84, 68, 36, 72, 44, 88, 76, 52
    };

    while (scanf("%d", &t), t) {
        for (c = 1; c <= t; c++) {
            scanf("%lld", &n);
            printf("Case %d: %d\n", c, n < 3 ? (n < 2 ? 2 : 6) : (d[(2 * n - 4) % 20] + d[(n - 3) % 20]) % 100);
        }
        putchar('\n');
    }

    return 0;
}

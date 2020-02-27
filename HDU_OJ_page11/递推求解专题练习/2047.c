#include <stdio.h>

// 一个长度为 n 的只由"E" "O" "F"三种字符组成的字符串（可以只有其中一种或两种字符，但绝对不能有其他字符
// 禁止在串中出现 O 相邻的情况，求一共有多少种满足要求的不同的字符串
// 当第 n 个是 O 时，那么第 n-1 个不能为 O，此种情况有 f(n-2) * 2 个
// 当第 n 个为非 O 时，有 f(n-1) * 2 个；
// 综上得递推公式：f(n) = f(n-2) * 2 + f(n-1) * 2
// http://acm.hdu.edu.cn/showproblem.php?pid=2047

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 1) {
            printf("3\n");
        } else {
            long long f1 = 3;
            long long f2 = 8;
            long long tmp;
            n--;
            while (--n) {
                tmp = f2;
                f2 = f1 * 2 + f2 * 2;
                f1 = tmp;
            }
            printf("%lld\n", f2);
        }
    }
}
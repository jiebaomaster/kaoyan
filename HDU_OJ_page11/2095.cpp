/*
 * 数组中，有一个数出现了奇数次，其他数出现了偶数次，求出现奇数次的那个数。
 * 由异或运算的性质：任何一个数异或它本身都等于零。则有：A^A=0，A^A^A=A。
 * 故只要将数列中所有数依次异或，最后得到的就是出现了奇数次的那个数。
 * http://acm.hdu.edu.cn/showproblem.php?pid=2095
 *
 * input:
 * 5
 * 1 1 3 2 2
 * 3
 * 1 2 1
 * output:
 * 3
 * 2
 */

#include <cstdio>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        int ans = 0, tmp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            ans ^= tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}
#include <stdio.h>
#include <math.h>

// 如果两个数中任何一个数都是另一个数的真约数之和，则这两个数就是亲和数。判断给定的两个数是否是亲和数
// http://acm.hdu.edu.cn/showproblem.php?pid=2040

int getSumOfApproximateNumber(int n) {
    int sum = 1;
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; ++i) { // 求约数只需要遍历到平方根，且一次可以求出一对约数
        if (n % i == 0) {
            sum += i + n / i;
        }
    }
    return sum;
}

int main() {
    int n;
    int a, b;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            if (getSumOfApproximateNumber(a) == b
                && getSumOfApproximateNumber(b) == a) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}
#include <stdio.h>

// 给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。
// http://acm.hdu.edu.cn/showproblem.php?pid=2007

int main() {
    int start, end, tmp;
    while (scanf("%d %d", &start, &end) != EOF) {
        if (start > end) tmp = end, end = start, start = tmp; // 考虑错误输入

        int oddSum = 0; // 奇数的立方和
        int evenSum = 0; // 偶数的平方和
        for (int i = start; i <= end; ++i) {
            if (i % 2 == 0) {
                evenSum += i * i;
            } else {
                oddSum += i * i * i;
            }
        }
        printf("%d %d\n", evenSum, oddSum);
    }
    return 0;
}
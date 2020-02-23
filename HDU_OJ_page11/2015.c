#include <stdio.h>

// 有一个长度为 n(n<=100)的数列，该数列定义为从2开始的递增有序偶数(2,4,6,8...)
// 现在要求你按照顺序每 m 个数求出一个平均值，如果最后不足 m 个，则以实际数量求平均值。编程输出该平均值序列。
// http://acm.hdu.edu.cn/showproblem.php?pid=2015

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int sum = 0; // 阶段和
        int count = 0; // 计步器，每逢 m 清零
        int firstOutput = 1;
        for (int i = 1; i <= n; ++i) {
            count++;
            sum += i * 2;
            if (count == m) {
                if (firstOutput) {
                    printf("%d", sum / m);
                    firstOutput = 0;
                } else {
                    printf(" %d", sum / m);
                }
                sum = 0;
                count = 0;
            }
        }
        if (count != 0) { // 最后几位不足 m 长的输出
            printf(" %d", sum / count);
        }
        printf("\n");
    }

    return 0;
}
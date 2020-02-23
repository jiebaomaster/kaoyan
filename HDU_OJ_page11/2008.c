#include <stdio.h>

// 统计给定的n个数中，负数、零和正数的个数。
// http://acm.hdu.edu.cn/showproblem.php?pid=2008

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        int zeroNumber = 0;
        int minusNumber = 0;
        int positiveNumber = 0;
        float number;
        for (int i = 0; i < n; ++i) {
            scanf("%f", &number);
            if (number < 0) {
                minusNumber++;
            } else if (number > 0) {
                positiveNumber++;
            } else {
                zeroNumber++;
            }
        }
        printf("%d %d %d\n", minusNumber, zeroNumber, positiveNumber);
    }

    return 0;
}
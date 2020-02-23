#include <stdio.h>

// 给你n个整数，求他们中所有奇数的乘积。
// http://acm.hdu.edu.cn/showproblem.php?pid=2006

int main() {
    int n; // 数组长度
    while (scanf("%d", &n) != EOF) {
        int sum = 1;
        for (int i = 0; i < n; ++i) { // 依次读入 n 个数，每次判断是否是奇数
            int number;
            scanf("%d", &number);
            if (number % 2 == 1) {
                sum *= number;
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
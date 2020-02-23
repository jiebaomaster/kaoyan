#include <stdio.h>

// 有n(n<=100)个整数，已经按照从小到大顺序排列好，现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。
// http://acm.hdu.edu.cn/showproblem.php?pid=2019

int main() {
    int n, x;
    while (scanf("%d %d", &n, &x) != EOF) {
        if (n == 0 && x == 0) { break; }

        int firstOutput = 1; // 是否是第一次输出
        int hasOutputX = 0; // 是否输出 x
        int number; // 当前读取的数据
        for (int i = 0; i < n; ++i) {
            scanf("%d", &number);
            if (number >= x && !hasOutputX) { // 当前数据与 x 相等时输出 x，否则 number 为最后一个数字是会漏掉 x
                hasOutputX = 1;
                if (firstOutput) {
                    firstOutput = 0;
                    printf("%d", x);
                } else {
                    printf(" %d", x);
                }
            }
            // 正常输出数组中每一个数据
            if (firstOutput) {
                firstOutput = 0;
                printf("%d", number);
            } else {
                printf(" %d", number);
            }
        }
        printf("\n");
    }

    return 0;
}
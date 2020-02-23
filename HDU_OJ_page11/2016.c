#include <stdio.h>
#include <stdlib.h>

// 输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
// http://acm.hdu.edu.cn/showproblem.php?pid=2016

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }

        int *data = (int *) malloc(sizeof(int) * n);
        int minIndex = 0; // 记录最小值索引，用于交换
        for (int i = 0; i < n; ++i) {
            scanf("%d", data + i);
            if (*(data + i) < *(data + minIndex)) {
                minIndex = i;
            }
        }
        // swap 0<->min
        int tmp = *data;
        *data = *(data + minIndex);
        *(data + minIndex) = tmp;

        // print
        for (int j = 0; j < n; ++j) {
            if (j == 0) {
                printf("%d", *(data + j));
            } else {
                printf(" %d", *(data + j));
            }
        }
        printf("\n");
    }
}
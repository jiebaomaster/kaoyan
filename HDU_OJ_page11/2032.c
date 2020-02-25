#include <stdio.h>

// 输出的杨辉三角的层数
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// http://acm.hdu.edu.cn/showproblem.php?pid=2032

int main() {
    int n;
    int yanghuiTriangle[30];
    yanghuiTriangle[0] = 1;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) { // 输出每一层
            for (int j = i; j > 0; --j) { // 从后往前遍历，计算第 i 层的值
                if (j == i) {
                    yanghuiTriangle[j] = 1;
                } else {
                    yanghuiTriangle[j] = yanghuiTriangle[j - 1] + yanghuiTriangle[j];;
                }
            }
            for (int k = 0; k <= i; ++k) { // output
                if (k == 0) {
                    printf("1");
                } else {
                    printf(" %d", yanghuiTriangle[k]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
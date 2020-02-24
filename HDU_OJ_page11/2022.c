#include <stdio.h>

// 寻找矩阵中绝对值最大的数
// http://acm.hdu.edu.cn/showproblem.php?pid=2022

int main() {
    int rows, cols;
    while (scanf("%d %d", &rows, &cols) != EOF) {
        int number;
        int max;
        int x = 0, y = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                scanf("%d", &number);
                if (i == 0 && j == 0) {
                    max = number;
                    continue;
                }
                if (number * number > max * max) {
                    x = i;
                    y = j;
                    max = number;
                }
            }
        }
        printf("%d %d %d\n", x + 1, y + 1, max);
    }
}
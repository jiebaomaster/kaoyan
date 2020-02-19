#include <stdio.h>
#include <stdlib.h>

/**
 * P233 从左上角到右下角，每次往下或右走，直到右下角，求走过的路径上元素值最大是几
 * 动态规划：f(i,j)表示到达坐标(i,j)的路径元素和最大值，则
 * f(i,j) = max{f(i-1,j), f(i,j-1)} + data[i][j]
 * @param matrix
 * @return
 */
int getMaxValueGift(int **matrix, int rows, int cols) {
    if (matrix == NULL || rows <= 0 || cols <= 0) {
        return -1;
    }

    // 对于f(i,j)，此时数组中存的是{f(i,0), f(i,1), ..., f(i,j-1), f(i-1, j), f(i-1, j+1), ... f(i-1, cols-1)}
    // 即前半段是本行 j 列之前的最大值，后半段是上一行 j 列开始直到最后一列的最大值，这样可以避免保存矩阵中所有元素的最大值，节省内存空间
    int *maxValue = (int *) malloc(sizeof(int) * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int left = 0;
            int top = 0;
            if (i > 0) {
                top = *(maxValue + j); // 向下走
            }
            if (j > 0) {
                left = *(maxValue + j - 1); // 向右走
            }
            *(maxValue + j) = *((int *) matrix + i * cols + j) + (top > left ? top : left);
        }
    }
    int result = maxValue[cols - 1];
    free(maxValue);
    return result;
}

int main() {
    int data[4][4] = {
            {1,  10, 3,  8},
            {12, 2,  9,  6},
            {5,  7,  4,  11},
            {3,  7,  16, 5}
    };
    printf("%d", getMaxValueGift((int **) data, 4, 4));

    return 0;
}
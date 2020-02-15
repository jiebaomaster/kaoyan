#include <stdio.h>
#include "../lib/getValueInTwoDimensionalArray.c"

/**
 * 顺时针打印矩阵中从坐标 [start][start] 开始的一圈
 * @param matrix
 * @param rows
 * @param cols
 * @param start
 */
void printMatrixInCircle(int **matrix, int rows, int cols, int start) {
    // 本圈遍历中右下角点的横纵坐标
    int endCol = cols - start - 1;
    int endRow = rows - start - 1;

    /**
     * ------➡ ️
     * ⬆  ️ |
     * |     |
     * ⬅----⬇  <--该点坐标 [endRow][endCol]
     * 第一步：从左到右，必须有
     * 第二步：从上到下，至少两行
     * 第三步：从右到左，至少两行两列
     * 第四步：从下到上，至少三行两列
     */
    // 第一步
    for (int i = start; i <= endCol; ++i) {
        printf("%d ", getValue(matrix, start, i, cols));
    }
    // 第二步
    if (endRow > start) {
        for (int i = start + 1; i <= endRow; ++i) {
            printf("%d ", getValue(matrix, i, endCol, cols));
        }
    }
    // 第三步
    if (endRow > start && endCol > start) {
        for (int i = endCol - 1; i >= start; --i) {
            printf("%d ", getValue(matrix, endRow, i, cols));
        }
    }
    // 第四步
    if (endRow - start > 1 && endCol > start) {
        for (int i = endRow - 1; i > start; --i) {
            printf("%d ", getValue(matrix, i, start, cols));
        }
    }
}

/**
 * P161 按顺时针方向从外向内打印矩阵
 * 每次从对角线上的元素开始，顺时针打印一圈，直到全部打印完
 * @param matrix
 * @param rows
 * @param cols
 */
void printMatrixClockwise(int **matrix, int rows, int cols) {
    if (matrix == NULL || rows <= 0 || cols <= 0) { return; }

    int start = 0;
    while (rows > start * 2 && cols > start * 2) { // 5*5 的矩阵最后一圈是 (2,2)，6*6 的矩阵最后一圈是 (2,2)
        printMatrixInCircle(matrix, rows, cols, start);
        start++;
    }
}

int main() {
    int matrix[4][4] = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
    printMatrixClockwise((int **) matrix, 4, 4);
}
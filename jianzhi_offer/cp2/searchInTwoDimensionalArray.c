#include <stdio.h>
#include <stdbool.h>

/**
 * 在一个行列均递增的二维数组中查找一个数
 * 从左上角 d[0][0] 开始的话，若目标 x 大于 d[0][0]，则有两条路可选，难以分辨
 * 现考虑从右上角 d[i][j] 开始搜索：
 *   若 x 小于 d[i][j]，则排除列 j
 *   若 x 大于 d[i][j]，则排除行 i
*/

bool search(int **numbers, int rowLength, int colLength, int target) {
    int i = 0, j = colLength - 1;
    while (i < rowLength && j >= 0) {
        // 注意这里对二维数组元素的访问，传递进函数的是一个二重指针
        int currentNumber = *((int *)numbers + i*colLength + j);
        if (currentNumber == target) {
            return true;
        } else if (currentNumber > target) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    int testData[4][4] = {
            {1, 2, 8,  9},
            {2, 4, 9,  12},
            {4, 7, 10, 13},
            {6, 8, 11, 15},
    };
    int target = 4;
    int result = search((int **)testData, 4, 4, target);
    printf("%d", result);

    return 0;
}
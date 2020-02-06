#include <stdio.h>
#include <stdbool.h>

/**
 * @param matrix 矩阵，以一维数组表示
 * @param rows 矩阵行数
 * @param cols 矩阵列数
 * @param currentRow 当前元素所在行索引
 * @param currentCol 当前元素所在列索引
 * @param string 待判断字符串
 * @param pathLength 当前比较到的string的元素索引
 * @param visited 是否已经访问数组
 * @return
 */
bool hasPathCore(char *matrix, int rows, int cols, int currentRow, int currentCol,
                 char *string, int *pathLength, bool *visited) {
    if (string[*pathLength] == '\0') {
        return true;
    }

    int hasPath = false;
    if (currentRow >= 0 && currentRow < rows
        && currentCol >= 0 && currentCol < cols
        && string[*pathLength] == matrix[currentRow * cols + currentCol]
        && !visited[currentRow * cols + currentCol]) {
        visited[currentRow * cols + currentCol] = true; // 标记当前位置已访问
        ++*pathLength; // 标记当前位置已匹配

        // 往上下左右四个方向继续寻找下一个位置
        hasPath = hasPathCore(matrix, rows, cols, currentRow - 1, currentCol, string, pathLength, visited) // 上
                  || hasPathCore(matrix, rows, cols, currentRow + 1, currentCol, string, pathLength, visited) // 下
                  || hasPathCore(matrix, rows, cols, currentRow, currentCol - 1, string, pathLength, visited) // 左
                  || hasPathCore(matrix, rows, cols, currentRow, currentCol + 1, string, pathLength, visited); // 右

        if (!hasPath) { // 如果沿着当前位置不能找出一条符合要求的路径，则需要回溯
            --*pathLength;
            visited[currentRow * cols + currentCol] = false;
        }
    }

    return hasPath;
}

/**
 * P89 判断矩阵中是否存在一条符合要求的路径
 * 二维数组中寻找路径的问题，通常都可以用回溯法解决
 * @param matrix
 * @param rows
 * @param cols
 * @param string
 * @return
 */
bool hasPath(char matrix[], int rows, int cols, char *string) {
    if (matrix == NULL || rows <= 0 || cols <= 0 || string == NULL) { return false; }
    // 初始化一个是否访问数组
    bool visited[rows * cols]; // 是否已经访问数组
    for (int k = 0; k < rows * cols; ++k) {
        visited[k] = false; // 所有位置初始化为未访问
    }
    // 从每个矩阵中的每个元素开始，寻找路径
    int pathLength=0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (hasPathCore(matrix, rows, cols, i, j, string, &pathLength, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char matrix[] = {'a', 'b', 't', 'g',
                     'c', 'f', 'c', 's',
                     'j', 'd', 'e', 'h'};
    printf("%d", hasPath(matrix, 3, 4, "gshedj"));

    return 0;
}
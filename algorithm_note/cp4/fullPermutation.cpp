#include <cstdio>
#include <cstring>

/**
 * 递归进行全排列
 * @param n
 * @param index 当前进行的排列的位数
 * @param number
 * @param visited
 */
void fullPermutationCore(int n, int index, int number[], bool visited[]) {
    if (index == n) {
        for (int i = 0; i < n; ++i) {
            printf("%d", number[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) { // 从最小的数1开始选择，若未被选用，则填入数字中，进行下一位选择
        if (!visited[i - 1]) {
            visited[i - 1] = true;
            number[index] = i;
            fullPermutationCore(n, index + 1, number, visited);
            visited[i - 1] = false; // 已处理完的子问题，还原状态
        }
    }
}

/**
 * P115 输出 1～n 个数字全排列组成的数
 * 例：n = 3，则输出 1，2，3 的全排列如下
 *     123，132，213，231，312，321
 * @param n
 */
void generateFulPermutation(int n) {
    bool *visitedHash = new bool[n]; // 标记某个数字是否已经选用的 hash 表
    memset(visitedHash, 0, sizeof(bool) * n);

    int *number = new int[n]; // 记录排列结果
    fullPermutationCore(n, 0, number, visitedHash);

    delete[] visitedHash;
    delete[] number;
}

int main() {
    generateFulPermutation(4);
}
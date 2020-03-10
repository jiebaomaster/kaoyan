#include <iostream>
#include <algorithm>

using namespace std;

/*
 * P426 数塔问题：有一个三角形数塔，现在要从第一层走到第最后一层，每次只能走向下一层连接的连个数字中的一个，
 * 问：最后将路径上所有数字相加后得道的和最大是多少
 * 令 dp[i][j]是第 i 层第 j 个数走到最后一层，路径上数字和的最大值，
 * 则有 dp[i][j] = max{dp[i+1][j], dp[i+1][j+1]} + f[i][j]
 */
const int maxn = 500;

int numberTower[5][5] = {
        {1},
        {8,  3},
        {12, 7,  16},
        {4,  10, 11, 6},
        {9,  5,  3,  9, 4}
};

/**
 *
 * @param n 数塔层数
 * @return
 */
int getMaxSumOfPath(int n) {
    int result[maxn]; // 分析可知，只需一维数组存储下一层的最优解
    memset(result, 0, maxn);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            result[j] = max(result[j], result[j + 1]) + numberTower[i][j];
        }
    }
    return result[0];
}

int main() {
    cout << getMaxSumOfPath(5) << endl;

    return 0;
}
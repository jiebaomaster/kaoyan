#include <cstdio>
#include <vector>

using namespace std;

/*
 * P273 从给定的 N 个数（可能为负数）中选择 K 个数，使其和为 X，求其中平方和最大的一组。
 * ⚠️一个数字可以多次选择
 */

const int maxn = 100;
int amountOfNumber; // 数字的总数
int targetSum; // 被选择的数字之和 X
int targetAmount; // 将要选择的数字个数 K
int numbers[maxn]; // 待数字序列
int maxSumOfSquares = 0; // 选中数字的最大平方和
vector<int> ans, tmp; // ans 存放平方和最大方案，tmp 存放临时方案

/**
 * 递归求解平方和最大方案
 * @param index 当前待选中数字的索引
 * @param curSum 当前已选择数字的和
 * @param curChooseAmount 当前已选择数字的个数
 * @param curSquares 当前已选择数字的平方和
 */
void dfs(int index, int curSum, int curChooseAmount, int curSquares) {
    if (curChooseAmount == targetAmount && curSum == targetSum) { // 找到 K 个数的和为 X
        if (curSquares > maxSumOfSquares) {
            maxSumOfSquares = curSquares;
            ans = tmp;
        }
    }
    if (index == amountOfNumber || curChooseAmount > targetAmount) { return; } // 处理完所有数或选择了大于 k 的数直接退出

    // 由于每个整数都可以被选多次，因此当选择了 index 号整数时，不应担直接进入 index+1 号的处理。
    // 应该能够继续选择 index 号，直到某时刻不再选择 index，就会通过"不选 index 号数"分支进入 index+1 号数的处理。
    // 选择 index 号数
    tmp.push_back(numbers[index]);
    dfs(index, curSum + numbers[index], curChooseAmount + 1, curSquares + numbers[index] + numbers[index]);
    tmp.pop_back();
    // 不选择 index 号数
    dfs(index + 1, curSum, curChooseAmount, curSquares);
}

int main() {
    while (scanf("%d %d %d", &amountOfNumber, &targetSum, &targetAmount) != EOF) {
        maxSumOfSquares = 0;
        ans.clear();
        tmp.clear();
        for (int i = 0; i < amountOfNumber; ++i) {
            scanf("%d", numbers + i);
        }
        dfs(0, 0, 0, 0);
        for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }
}

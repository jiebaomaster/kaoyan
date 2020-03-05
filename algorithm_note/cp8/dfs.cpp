#include <cstdio>

using namespace std;

// P271 有 n 件物品，总量分别为 w[]，价值分别为 v[]。现从中选择若干件放入一个最大承重为 V 的背包中，求可得的最大物品价值。

const int maxn = 100;
int maxValueOfPackage = 0;
int value[maxn]; // 物品价值数组
int weight[maxn]; // 物品重量数组
int chooseAmount; // 待选择的物品数量
int packageCapacity; // 背包最大可承受重量

/**
 * 对于每件物品，可以选中也可以不选中（二叉树），直到选完最后一件物品为止（深度优先）
 * 可以看出本题为对于一个给定的序列，遍历其所有的子序列，找到一个最优序列
 * @param index
 * @param curWeightSum
 * @param curValueSum
 */
void dfs(int index, int curWeightSum, int curValueSum) {
    if (index == chooseAmount) { return; }

    dfs(index + 1, curWeightSum, curValueSum); // 该序号物品不被选中，则进行选中下一个物品

    if (weight[index] + curWeightSum <= packageCapacity) { // 若选中该物品后不超过背包容量，则可选中这个物品
        if (value[index] + curValueSum > maxValueOfPackage) {
            maxValueOfPackage = value[index] + curValueSum;
        }
        // 选中本序号物品，更新当前已有重量与价值，继续进行下一个物品的选择
        dfs(index + 1, curWeightSum + weight[index], curValueSum + value[index]);
    }
}

int main() {
    while (scanf("%d %d", &chooseAmount, &packageCapacity) != EOF) {
        maxValueOfPackage = 0;
        for (int i = 0; i < chooseAmount; ++i) {
            scanf("%d", weight + i);
        }
        for (int i = 0; i < chooseAmount; ++i) {
            scanf("%d", value + i);
        }
        dfs(0, 0, 0);
        printf("%d\n", maxValueOfPackage);
    }
    return 0;
}


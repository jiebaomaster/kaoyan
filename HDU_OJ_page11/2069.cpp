/*
 * Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent.
 * We want to make changes with these coins for a given amount of money.
 * Write a program to find the total number of different ways of making changes for any amount of money in cents.
 * Your program should be able to handle up to 100 coins.
 * http://acm.hdu.edu.cn/showproblem.php?pid=2069
 */

#include <cstdio>

using namespace std;

int coin[] = {50, 25, 10, 5, 1}; // 硬币面额

long long count; // 符合要求的组合数

/**
 * dfs 遍历所有硬币的选择方式
 * @param n 剩余面额
 * @param i 当前选择硬币面额在 coin 中的索引
 * @param coinNum 已使用硬币的数量
 */
void dfs(int n, int i, int coinNum) {
    if (i == 5 || n <= 0 || coinNum > 100) {
        if (n == 0 && coinNum <= 100) {
            count++;
        }
        return;
    }
    dfs(n - coin[i], i, coinNum + 1); // 选择该位置的硬币
    dfs(n, i + 1, coinNum); // 不选中该位置的硬币，转而选择下一个
}

/*
 * input:
 * 11
 * 26
 * output:
 * 4
 * 13
 */
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        count = 0;
        dfs(n, 0, 0);
        printf("%lld\n", count);
    }

    return 0;
}

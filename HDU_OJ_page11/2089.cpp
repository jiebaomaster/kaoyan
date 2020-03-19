/*
 * 统计数字区间内不含 62 和 4 的数的个数
 * 数位DP
 * https://blog.csdn.net/wust_zzwh/article/details/52100392
 * https://www.bilibili.com/video/av27156563
 *
 * http://acm.hdu.edu.cn/showproblem.php?pid=2089
 *
 */

#include <cstdio>
#include <cstring>

long long dp[10][2]; // 当前枚举到 index 位，前面一位枚举的是pre(更加前面的位已经合法了)的符合要求数个数
int num[10]; // 按位拆分的数字，位排列为：个，十，百...

/**
 * 数位dp，即用记忆化存储优化数数的过程，边界情况特殊处理
 * 从高位数到低位，统计每一位包含的数的个数
 * @param index 当前位
 * @param pre6 前一位是否是6
 * @param limit 前一位是否到达边界
 * @return
 */
long long dfs(int index, bool pre6, bool limit) {
    if (index == -1) { return 1; } // 递归边界，既然是按位枚举，最低位是0，那么 index==-1 说明这个数我枚举完了
    if (!limit && dp[index][pre6] != -1) { return dp[index][pre6]; }

    long long count = 0;
    int up = limit ? num[index] : 9;
    for (int i = 0; i <= up; ++i) {
        if (pre6 && i == 2) { continue; }
        if (i == 4) { continue; }
        count += dfs(index - 1, i == 6, limit && i == num[index]); // 状态转移
    }
    if (!limit) { dp[index][pre6] = count; }

    return count;
}

/**
 * 计算 0～n 内的符合要求的数字个数
 * @param n
 * @return
 */
long long solve(int n) {
    int index = 0;
    while (n) { // 将数字按位拆分
        num[index++] = n % 10;
        n /= 10;
    }
    return dfs(index - 1, false, true);
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) { break; }
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(m) - solve(n - 1));
    }

    return 0;
}
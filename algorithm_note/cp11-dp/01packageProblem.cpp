#include <iostream>
#include <algorithm>

using namespace std;

/*
 * P443 01背包问题：
 * 有 n 件物品，每件物品的重量为 w[i]，价值为 c[i]。
 * 现有一个容量为 V 的背包，问如何去物品放入背包，使得背包内物品的总价值最大。其中每种物品都只有一件。
 *
 * 令 dp[i][v] 表示前 i 件物品（1<=i<=n, 0<=v<=V）恰好装入容量为 v 的背包中所能获得的最大价值。考虑第 i 件物品的选择策略：
 *   1. 不放第 i 件物品，那么问题转化为前 i-1 件物品恰好装入容量为 v 的背包中所能获得的最大价值，即 dp[i-1][v]
 *   2. 放入第 i 件物品，那么问题转化为前 i-1 件物品恰好装入容量为 v-w[i] 的背包中所能获得的最大价值，即 dp[i-1][v-w[i]]+c[i]
 * 则 dp[i][v] = max{dp[i-1][v], dp[i-1][v-w[i]]+c[i]}（1<=i<=n, w[i]<=v<=V）
 * 边界：dp[0][v]=0，即前 0 件物品放入任何容量为 v 的背包中都只能获得价值 0
 */

const int maxn = 100; // 最大物品件数
const int maxV = 1000; // 最大背包容量

int w[maxn], c[maxn], dp[maxn][maxV];

/*
 * input:
 * 5 8
 * 3 5 1 2 2
 * 4 5 2 1 3
 * output:
 * 10
 */
int main() {
    int n, V; // 物品件数，背包容量
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    // 边界
    for (int v = 0; v <= V; ++v) {
        dp[0][v] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int v = w[i]; v <= V; ++v) { // v 从 w[i] 开始，保证了第 i 件物品一定能被放入背包中
            dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - w[i]] + c[i]);
        }
    }

    int max = 0;
    for (int v = 0; v <= V; ++v) {
        if (dp[n][v] > max) {
            max = dp[n][v];
        }
    }
    cout << max;

    return 0;
}

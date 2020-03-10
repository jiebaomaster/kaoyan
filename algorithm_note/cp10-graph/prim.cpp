#include <iostream>
#include <algorithm>

using namespace std;

/*
 * P405 prim 算法求解最小生成树，求最小生成树的边权之和
 * prim 算法的思想可以简单表述为，每次从未加入集合 V-S 中寻找距离 最小生成树点集 S 距离最近的点 v，将 v 加入 S，直到点全在 S 中为止
 * 可以发现 prim 与 Dijkstra 使用的思想完全相同，只在数组 d[] 的含义上有差别。其中 Dijkstra 的 d[] 含义为起点到顶点 Vi 的距离，
 * prim 的 d[] 含义为最小生成树点集 S 到顶点 Vi 的距离，即两者的区别仅在于最短距离是顶点 Vi 针对 "起点" 还是 "集合 S"
 */

const int maxn = 1010;
const int INF = 100000000;
int G[maxn][maxn]; // 图
int d[maxn]; // 点距离最小生成树点集 S 的最短距离
bool isInSet[maxn]; // 点是否在最小生成树点集 S 中

int nodeNum;
int edgeNum;
int lengthSumMST; // 最小生成数的边权之和

/**
 * prim 算法求解最小生成树
 */
void prim() {
    memset(isInSet, false, sizeof(isInSet));
    fill(d, d + nodeNum, INF);
    d[0] = 0; // 从 0 号节点开始求解最小生成树
    lengthSumMST = 0;
    for (int i = 0; i < nodeNum; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < nodeNum; ++j) {
            if (!isInSet[j] && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if (u == -1) { return; }
        isInSet[u] = true; // 将与集合距离最小的集合加入最小生成树
        lengthSumMST += d[u]; // 加入一个点之后累加其与 S 的距离
        for (int k = 0; k < nodeNum; ++k) {
            if (!isInSet[k] && G[u][k] != INF
                && G[u][k] < d[k]) { // 以 u 为中介点可使 k 离集合 S 更近
                d[k] = G[u][k];
            }
        }
    }
}

/*
 * input:
 * 6 10
 * 0 1 4
 * 0 4 1
 * 0 5 2
 * 1 2 6
 * 1 5 3
 * 2 3 6
 * 2 5 5
 * 3 4 4
 * 3 5 5
 * 4 5 3
 * output:
 * 15
 */
int main() {
    fill(G[0], G[0] + maxn * maxn, INF);
    cin >> nodeNum >> edgeNum;
    int start, end, length;
    for (int i = 0; i < edgeNum; ++i) {
        cin >> start >> end >> length;
        G[start][end] = length;
        G[end][start] = length;
    }
    prim();
    cout << lengthSumMST;

    return 0;
}

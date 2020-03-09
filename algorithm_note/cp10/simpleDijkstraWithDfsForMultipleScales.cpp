#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * P385 给出 N 个城市，M 条路，每条路的距离和过路费已知，求一条距离最短且话费相对较小的路径。
 * 本题为二重尺度（距离 + 边权）下的最短路径问题，可以先用简单 Dijkstra 算法解出所有最短路径，最后 dfs 遍历所有得到的最短路径求出符合要求的那一条。
 * Dijkstra + dfs 的方法适合计算多重尺度下的最短路径问题，且针对不同问题每次需要修改的地方只有dfs比较部分，可以作为一种模版化解法
 */

const int maxn = 510;
const int INF = 1000000000;
int G[maxn][maxn]; // 距离图
int d[maxn]; // 每个城市与起点的最短距离
bool isInPath[maxn]; // 集合 S
vector<int> pre[maxn]; // 每个城市的前序节点，由于会有多条路径距离相等的情况，故每个节点的前序是一个可变长数组
vector<int> path; // 所求的最短路径
vector<int> tmpPath; // 临时最短路径

int fee[maxn][maxn]; // 过路费边权图
int totalFee; // 总过路费

int cityNum;
int loadNum;
int start;
int dest;

/**
 * Dijkstra 算法解决单源最短路径问题，且将每个节点的前序节点存放在 pre 中
 * @param start
 */
void dijkstra(int start) {
    memset(isInPath, false, sizeof(isInPath));
    fill(d, d + cityNum, INF);
    d[start] = 0;
    for (int i = 0; i < cityNum; ++i) {
        int min = INF, u = -1;
        for (int j = 0; j < cityNum; ++j) {
            if (!isInPath[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) { return; }
        isInPath[u] = true;
        for (int k = 0; k < cityNum; ++k) { // 已找到的最优点作为中间点去优化不在集合内点的路径
            if (G[u][k] != INF && !isInPath[k]) {
                if (G[u][k] + d[u] < d[k]) { // 以 u 为中间节点使 d[k] 更小
                    d[k] = G[u][k] + d[u];
                    pre[k].clear(); // 清空 pre[k]
                    pre[k].push_back(u); // u 作为前序加入 pre[k]
                } else if (G[u][k] + d[u] == d[k]) {
                    pre[k].push_back(u); // 找到相同长度的路径，u 为 k 的前驱之一
                }
            }
        }
    }
}

/**
 * dfs遍历所有的路径，寻找符合条件的路径
 * 只要从终点开始沿着 pre 一直往前访问每个节点的前驱，直到起点为止（类比并查集找根），就可得到一条最短路径
 * @param index 当前访问的节点
 */
void dfs(int index) {
    if (index == start) { // 走到起点，即取得一条最短路径保存在 tmpPath 中
        tmpPath.push_back(start);
        int tmpFee = 0;
        for (int i = 1; i < tmpPath.size(); ++i) { // 遍历路径，计算边权之和
            tmpFee += fee[tmpPath[i]][tmpPath[i - 1]];
        }
        if (tmpFee < totalFee) { // 保留最短边权的值和此时路径
            totalFee = tmpFee;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(index);
    for (int i = 0; i < pre[index].size(); ++i) { // 遍历某一个节点的全部前驱
        dfs(pre[index][i]);
    }
    tmpPath.pop_back();
}

/*
 * input:
 * 4 5 0 3
 * 0 1 1 20
 * 1 3 2 30
 * 0 3 4 10
 * 0 2 2 20
 * 2 3 1 20
 * output:
 * 0 2 3 3 40
 */
int main() {
    cin >> cityNum >> loadNum >> start >> dest;
    fill(G[0], G[0] + maxn * maxn, INF);
    totalFee = INF;
    int ss, dd, dist, cost;
    for (int i = 0; i < loadNum; ++i) {
        cin >> ss >> dd >> dist >> cost;
        G[ss][dd] = dist;
        G[dd][ss] = dist;
        fee[ss][dd] = cost;
        fee[dd][ss] = cost;
    }
    dijkstra(start);
    dfs(dest);
    for (int j = path.size() - 1; j >= 0; --j) { // path 中是反向存储的，故要反向输出
        cout << path[j] << ' ';
    }
    cout << d[dest] << " " << totalFee;
}

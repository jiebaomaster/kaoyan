#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * P416 拓扑排序，判断一个图是否是有向无环图 DAG
 */

const int maxn = 1010;
vector<int> G[maxn]; // 邻接表
int inDegree[maxn]; // 每个顶点的入度
int nodeNum;

/**
 * 拓扑排序，判断一个图是否是有向无环图 DAG
 * @return
 */
bool topologicalSort() {
    int num = 0; // 拓扑排序遍历到的节点个数
    queue<int> q;
    for (int i = 0; i < nodeNum; ++i) { // 将所有入度为 0 的节点入队，这些顶点可以直接输出
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' '; // 输出拓扑序列
        for (int i = 0; i < G[node].size(); ++i) { // 遍历点 node 的所有后继
            int next = G[node][i];
            inDegree[next]--; // 后继顶点的入度减 1
            if (inDegree[next] == 0) { // 若后继顶点的入度为 0，则入队，可以输出
                q.push(next);
            }
        }
        num++; // 累加计算拓扑排序遍历到的节点个数
    }
    return num == nodeNum; // 遍历完全部节点，则该图是一个有向无环图
}
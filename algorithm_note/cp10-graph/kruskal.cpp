#include <iostream>
#include <algorithm>

using namespace std;
/*
 * P411 kruskal 算法求解最小生成树，求最小生成树的边权之和
 * kruskal 算法的思想可以简单表述为：每次选择图中最小边权的边，如果边两端的顶点在不同的连通快中，就把这条边加入最小生成树中
 * 实现中主要有两个问题：1. 如何判断边的两个端点是否在不同的连通快中；2. 如何将边加入最小生成树中
 * 可以发现，以上两个问题可以很好地用 "并查集" 解决
 */
const int maxV = 110;
const int maxE = 10010;

int nodeNum;
int edgeNum;
int lengthSumMST; // 最小生成数的边权之和

struct edge {
    int start, end; // 边的两个端点
    int weight; // 边权
} edges[maxE]; // 存放所有边的数组

/**
 * 比较两个边的大小，用在排序函数中
 * @param e1
 * @param e2
 * @return
 */
bool cmpEdge(edge e1, edge e2) {
    return e1.weight < e2.weight;
}

int father[maxV]; // 并查集数组

/**
 * 查询节点所在集合的根节点
 * @param x
 * @return
 */
int _find(int x) {
    while (father[x] != x) {
        x = father[x];
    }
    return x;
}

/**
 * kruskal 算法求解最小生成树
 */
void kruskal() {
    lengthSumMST = 0;
    int curEdgeNum = 0; // 当前生成树边数
    for (int i = 0; i < nodeNum; ++i) { // 初始化并查集
        father[i] = i;
    }
    sort(edges, edges + edgeNum, cmpEdge); // 所有边按边权从小到大排列，求最小生成树时只需从前向后取边
    for (int j = 0; j < edgeNum; ++j) { // 遍历所有边
        int startFather = _find(edges[j].start); // 查询测试边两个端点所在集合的根节点
        int endFather = _find(edges[j].end);
        if (startFather != endFather) { // 若测试边两个端点同一集合中
            father[startFather] = endFather; // 合并集合，即把测试边加入最小生成树中
            lengthSumMST += edges[j].weight; // 累加生成树边权和
            curEdgeNum++; // 当前生成树的边数加 1
            if (curEdgeNum == nodeNum - 1) { return;} // 边数等于节点数减 1 时，最小生成树已经产生，可以退出
        }
    }
    if (curEdgeNum != nodeNum - 1) { // 不是连通图时报错
        cout << "无法构成连通图!" << endl;
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
    cin >> nodeNum >> edgeNum;
    for (int i = 0; i < edgeNum; ++i) { // input edges
        cin >> edges[i].start >> edges[i].end >> edges[i].weight;
    }
    kruskal();
    cout << lengthSumMST;

    return 0;
}

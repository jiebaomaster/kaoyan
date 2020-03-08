#include <iostream>
#include <algorithm>

using namespace std;

/*
 * P378 给出 N 个城市，M 个无向边。每个城市有一定数量的救援小组，所有边的边权已知。
 * 现给出终点和起点，求从起点到终点的最短路径条数及最短路径上的救援小组数量之和，若有多条最短路径，输出救援小组数量最大的。
 * 运用 Dijkstra 算法求单源最短路径，本题属于其变式，只需要修改优化D[v]的代码即可
 */

const int maxn = 1010;
const int INF = 1000000000; // 10^9，两点间距离无穷大，代表两点不相连

int G[maxn][maxn] = {INF}; // 图的邻接矩阵
int cityDistance[maxn]; // 各顶点距离起点的距离
bool isInPath[maxn];
int rescueTeamNumberOfCity[maxn]; // 每个城市的救援小组数量
int pathNumber[maxn]; // 最短路径上每个城市的路径条数
int rescueTeamInShortestPath[maxn]; // 最短路径上每个城市可或得的救援小组数量之和

int cityNumber;
int roadNumber;

/**
 * 运用 Dijkstra 算法求单源最短路径
 * 算法实现中关键点：
 * 1. 已加入的点集合 S，可以用一个 bool 类型的数组，值为 true 表示一点已经加入
 * 2. 起点 s 到达各顶点的最短距离，将这些距离用一个数组 d[]，除了起点到自身的距离为 0 其余的初始化为一个很大的数，每次循环更新 d[]
 * 3. 每次循环都会加入一个点到集合 S 中，则经过 n 次循环就能得到所有的最短路径长度，存储在 d[] 中
 * @param start
 */
void dijkstra(int start) {
    // 初始化 距离、集合
    memset(isInPath, false, sizeof(bool) * cityNumber);
    fill(cityDistance, cityDistance + cityNumber, INF);
    cityDistance[start] = 0;
    // 初始化 每个城市的救援小组数量
    memset(rescueTeamInShortestPath, 0, sizeof(int) * cityNumber);
    rescueTeamInShortestPath[start] = rescueTeamNumberOfCity[start];
    // 初始化 最短路径上每个城市的路径条数
    memset(pathNumber, 0, sizeof(int) * cityNumber);
    pathNumber[start] = 1;

    for (int k = 0; k < cityNumber; ++k) { // 循环 n 次
        int d = INF;
        int min = -1;
        for (int i = 0; i < cityNumber; ++i) { // 找到当前距离最小的点
            if (!isInPath[i] && cityDistance[i] < d) {
                min = i;
                d = cityDistance[i];
            }
        }
        if (d == INF) { return; } // 此时剩余的点都和起点不相连
        isInPath[min] = true; // 将找到的点加入到集合中
        for (int j = 0; j < cityNumber; ++j) { // 已找到的最优点作为中间点去优化不在集合内点的路径
            if (!isInPath[j] && G[min][j] != INF) { // j 不在集合内 且 通过 min 能到达 j
                if (cityDistance[j] > cityDistance[min] + G[min][j]) { // 第一标尺（距离）比较，通过中间点 min 可以使距离更优
                    cityDistance[j] = cityDistance[min] + G[min][j];
                    rescueTeamInShortestPath[j] = rescueTeamInShortestPath[min] + rescueTeamNumberOfCity[j];
                    pathNumber[j] = pathNumber[min];
                } else if (cityDistance[j] == cityDistance[min] + G[min][j]) { // 两条路径的长度相同
                    // 第一标尺相等时，第二标尺（救援小组数量）比较
                    if (rescueTeamInShortestPath[min] + rescueTeamNumberOfCity[j] > rescueTeamInShortestPath[j]) {
                        rescueTeamInShortestPath[j] = rescueTeamInShortestPath[min] + rescueTeamNumberOfCity[j];
                    }
                    pathNumber[j] += pathNumber[min]; // 最短距离相等时，说明有多条路径到达点 j，路径条数累加
                }
            }
        }
    }
}

/*
 * input:
 * 5 6 0 2
 * 1 2 1 5 3
 * 0 1 1
 * 0 2 2
 * 0 3 1
 * 1 2 1
 * 2 4 1
 * 3 4 1
 * output:
 * 2 4
 */
int main() {
    int start, dist;
    cin >> cityNumber >> roadNumber >> start >> dist;
    for (int i = 0; i < cityNumber; ++i) {
        cin >> rescueTeamNumberOfCity[i];
    }
    fill(G[0], G[0] + maxn * maxn, INF); // 初始化图，二维数组连续存放，可以按一维初始化
    int roadStart, roadEnd, length;
    for (int j = 0; j < roadNumber; ++j) {
        cin >> roadStart >> roadEnd >> length;
        G[roadStart][roadEnd] = length; // 无向图的输入是双向的
        G[roadEnd][roadStart] = length;
    }

    dijkstra(start);
    cout << pathNumber[dist] << " " << rescueTeamInShortestPath[dist] << endl;

    return 0;
}



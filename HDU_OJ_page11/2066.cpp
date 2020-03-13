/*
 * 输入数据有多组，每组的第一行是三个整数T，S和D，表示有T条路，和草儿家相邻的城市的有S个，草儿想去的地方有D个；
 * 接着有T行，每行有三个整数a，b，time,表示a,b城市之间的车程是time小时；(1=<(a,b)<=1000;a,b 之间可能有多条路)
 * 接着的第T+1行有S个数，表示和草儿家相连的城市；接着的第T+2行有D个数，表示草儿想去地方。
 * 输出草儿能去某个喜欢的城市的最短时间。
 * 多起点最短路径问题，可以设一个新的源点 0，将所有起点连接到源点，且源点到起点之间的距离都为 0，则只需一次 Dijkstra 就可得各最短路径
 * http://acm.hdu.edu.cn/showproblem.php?pid=2066
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
const int INF = 1000000000;
int map[maxn][maxn];
int d[maxn];
bool set[maxn];

int roadNum, adjacentCityNum, targetCityNum;
int adjacentCity[maxn];
int targetCity[maxn];

void dijkstra() {
    memset(set, false, sizeof(set));
    fill(d, d + maxn, INF);
    d[0] = 0;
    for (int i = 0; i < maxn; ++i) {
        int min = INF;
        int u = -1;
        for (int j = 0; j < maxn; ++j) {
            if (!set[j] && min > d[j]) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) { return; }
        set[u] = true;
        for (int v = 0; v < maxn; ++v) {
            if (!set[v] && map[u][v] != INF && map[u][v] + d[u] < d[v]) {
                d[v] = map[u][v] + d[u];
            }
        }
    }
}

/*
 * input:
 * 6 2 3
 * 1 3 5
 * 1 4 7
 * 2 8 12
 * 3 8 4
 * 4 9 12
 * 9 10 2
 * 1 2
 * 8 9 10
 * output:
 * 9
 */
int main() {
    int x, y, time;
    while (scanf("%d%d%d", &roadNum, &adjacentCityNum, &targetCityNum) != EOF) {
        fill(map[0], map[0] + maxn * maxn, INF);
        for (int i = 0; i < roadNum; ++i) {
            scanf("%d%d%d", &x, &y, &time);
            if (time < map[x][y]) { // ⚠️题目这里有坑，a,b 之间可能有多条路，所以map[][]要保存两点间边权最小的边。
                map[x][y] = time;
                map[y][x] = time;
            }
        }
        for (int i = 0; i < adjacentCityNum; ++i) {
            scanf("%d", &adjacentCity[i]);
            map[0][adjacentCity[i]] = map[adjacentCity[i]][0] = 0; // 所有与小草相邻的城市与源点的距离初始化为 0
        }
        for (int i = 0; i < targetCityNum; ++i) {
            scanf("%d", &targetCity[i]);
        }

        dijkstra();

        int minTime = INF;
        for (int i = 0; i < targetCityNum; ++i) {
            if (d[targetCity[i]] < minTime) {
                minTime = d[targetCity[i]];
            }
        }
        printf("%d\n", minTime);
    }

    return 0;
}
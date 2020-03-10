#include <string>
#include <map>
#include <iostream>

using namespace std;

/*
 * P354 一群人有一些两两的好友关系，一个组的总边权超过 K，成员人数超过 2，即可视为犯罪团伙，而组内点权最大的人为头目，
 * 输出团伙的个数，每个团伙的头目和成员人数
 * 易知每个所有成员构成一个带权图，每个团伙是一个连通分量，可以选用 dfs 的方式求连通分量
 * 本题也可以使用并查集解决，只要保证合并集合的时候总是权值大的那个作为根即可得到头目
 */

const int maxn = 2010;

map<int, string> intToString; // 编号 -> 姓名
map<string, int> stringToInt; // 姓名 -> 编号
map<string, int> Gang; // head -> 人数

int G[maxn][maxn] = {0}; // 代表图的邻接矩阵，0 代表两点间无连接
int weightOfPeople[maxn] = {0}; // 每个人的点权，用来区分老大
int n; // 边数
int k; // 每个团伙的边权之和下限
int personNum = 0; // 总人数
bool visited[maxn] = {false};

/**
 * 将一个姓名映射为数字，方便遍历操作
 * @param str
 * @return
 */
int mapStringToInt(string str) {
    if (stringToInt.find(str) != stringToInt.end()) { // 若当前姓名已存在，直接返回其数字
        return stringToInt[str];
    } else {
        stringToInt[str] = personNum; // 用当前输入姓名数量做id
        intToString[personNum] = str;
        return personNum++;
    }
}

/**
 * 以一点出发，计算其所在团伙的老大，团伙成员数量，团伙成员点权之和
 * @param curPeople
 * @param head
 * @param numMember
 * @param totalValue
 */
void dfs(int curPeople, int &head, int &numMember, int &totalValue) {
    numMember++;
    visited[curPeople] = true;
    totalValue += weightOfPeople[curPeople];
    if (weightOfPeople[head] < weightOfPeople[curPeople]) { // 当前节点的点权大于头目，则更新头目
        head = curPeople;
    }
    for (int i = 0; i < personNum; ++i) {
        if (G[curPeople][i] > 0 && !visited[i]) { // 遍历邻接矩阵中所有与当前节点有连接的点
            dfs(i, head, numMember, totalValue);
        }
    }
}

/**
 * 遍历每个连通分量，计算所有的团伙信息
 */
void calAllGangByDfs() {
    for (int i = 0; i < personNum; ++i) {
        if (!visited[i]) {
            int head = i, numMember = 0, totalValue = 0;
            dfs(i, head, numMember, totalValue);
            if (numMember > 2 && totalValue / 2 > k) { // 点权之和/2 = 边权之和
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

/*
 * input:
 * 8 59
 * AAA BBB 10
 * BBB AAA 20
 * AAA CCC 40
 * DDD EEE 5
 * EEE DDD 70
 * FFF GGG 30
 * GGG HHH 20
 * HHH FFF 10
 * output:
 * 2
 * AAA 3
 * GGG 3
 */
int main() {
    int w;
    string string1, string2;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) { // input
        cin >> string1 >> string2 >> w;
        int p1 = mapStringToInt(string1);
        int p2 = mapStringToInt(string2);
        G[p1][p2] += w; // 将输入的有向关系看成是无向图，故双方对应的边权都要加 w
        G[p2][p1] += w;
        weightOfPeople[p1] += w; // 输入时统计双方的点权
        weightOfPeople[p2] += w;
    }
    calAllGangByDfs();
    cout << Gang.size() << endl;
    for (map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++) { // output，map 中按 key 的字典序排列元素
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}



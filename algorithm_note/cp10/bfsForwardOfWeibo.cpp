#include <iostream>
#include <queue>

using namespace std;
/*
 * P363 给出微博中的几个人，每个人关注的其他人，当一个人发布动态的时候可以被关注他的人转发，求经过 L 层转发后，总共最大被转发了几次
 * 微博人的关注关系构成一张图，本题与层级有关，应选用 BFS 解决
 */
const int maxn = 1010;
typedef struct Node {
    int no; // 节点编号
    int level; // 节点所在层级
} node;

bool G[maxn][maxn] = {false}; // 图的邻接矩阵
bool hasInQueue[maxn] = {false};

/**
 * 计算从 k 发送的动态，在层级 level 下最多能被基本转发
 * @param k
 * @param level
 * @return
 */
int countForward(int k, int level) {
    int count = 0;
    queue<node> q;
    hasInQueue[k] = true;
    node kNode = {k, 0};
    q.push(kNode);
    while (!q.empty()) {
        node topNode = q.front();
        q.pop();
        for (int i = 0; i < maxn; ++i) {
            if (topNode.level < level && G[topNode.no][i] && !hasInQueue[i]) { // 父节点层级小于l，有关注关系，未入队过
                hasInQueue[i] = true;
                node iNode = {i, topNode.level + 1};
                q.push(iNode);
                count++;
            }
        }
    }
    return count;
}

/*
 * input:
 * 7 3
 * 3 2 3 4
 * 0
 * 2 5 6
 * 2 3 1
 * 2 3 4
 * 1 4
 * 1 5
 * 2 2 6
 * output:
 * 4
 * 5
 */
int main() {
    int n, l;
    cin >> n >> l;
    int followNum; // 关注的总数
    int followIndex; // 被关注的人id
    for (int i = 1; i <= n; ++i) { // input edge
        cin >> followNum;
        for (int j = 0; j < followNum; ++j) {
            cin >> followIndex;
            G[followIndex][i] = true; // i 关注了 followIndex，则 followIndex 发送的动态可以被 i 转发
        }
    }
    int m, k;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        memset(hasInQueue, false, sizeof(hasInQueue));
        cin >> k;
        cout << countForward(k, l) << endl;
    }

    return 0;
}

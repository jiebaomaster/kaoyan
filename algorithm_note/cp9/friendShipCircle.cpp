#include <cstdio>

using namespace std;

/*
 * P332 一群人有一些两两的好友关系，且好友关系具有自反性和传递性，问可以将这些人分成几组，组内任意两人为好友，组间任意两人不为好友
 * 易知，互相为好友的一群人构成一个集合，即求共可以构成几个集合
 * 并查集的应用
 */
const int maxn = 100;
int fatherId[maxn]; // 元素的父亲节点数组

/**
 * 查找 x 元素的根节点
 * @param x
 * @return
 */
int _find(int x) {
    int fatherIndex = x;
    while (fatherId[fatherIndex] != fatherIndex) {
        fatherIndex = fatherId[fatherIndex];
    }
    // 路径压缩，即将从元素 x 开始一直到根节点的元素的父亲都直接指向根节点，可以加速下次父节点查询O(1)，P330
    while (fatherId[x] != fatherIndex) {
        int tmp = fatherId[x];
        fatherId[x] = fatherIndex; // 更改父亲为根节点
        x = tmp; // 路径回溯
    }
    return fatherIndex;
}

/**
 * 求两个元素所在集合的并集
 * @param a
 * @param b
 * @return 集合合并后根节点的位置
 */
int _union(int a, int b) {
    int father_a = _find(a);
    int father_b = _find(b);
    if (father_a != father_b) {
        fatherId[father_a] = father_b;
    }
    return father_b;
}

int main() {
    int numberOfPeople;
    int numberOfFriendShip;
    scanf("%d%d", &numberOfPeople, &numberOfFriendShip);
    for (int i = 1; i <= numberOfPeople; ++i) {
        fatherId[i] = i;
    }
    int a, b;
    while (numberOfFriendShip--) {
        scanf("%d%d", &a, &b);
        _union(a, b);
    }
    int count = 0;
    for (int j = 1; j <= numberOfPeople; ++j) { // 查找共有几个根节点即可得有几个集合
        if (fatherId[j] == j) { count++; }
    }
    printf("%d", count);

    return 0;
}
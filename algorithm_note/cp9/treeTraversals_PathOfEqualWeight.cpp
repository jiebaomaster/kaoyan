#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * P305 求一个树中所有从根节点到叶子节点的路径，使得每条路径上的节点的权值之和等于给定的常数 S。
 * 若有多条路径，按节点序从大到小打印
 */
const int maxn = 100;
struct Node { // 树的节点
    int weight; // 节点的权值
    vector<int> children; // 该节点所有子节点的索引
} treeNodes[maxn]; // 用一个节点数组表示一个树，根节点为0号，树的静态写法 P302

vector<int> path; // 存放临时路径的栈

/**
 * 递归dfs，寻找每条符合要求的路径
 * @param root
 * @param curWeightSum
 * @param targetWeightSum
 */
void findPathOfEqualWeight(int root, int curWeightSum, int targetWeightSum) {
    if (curWeightSum > targetWeightSum) { return; }
    if (curWeightSum == targetWeightSum) {
        if (treeNodes[root].children.empty()) { // 若一个节点的子节点为空，则该节点为叶子节点
            for (int i = 0; i < path.size(); ++i) { // 打印符合要求的路径
                if (i != 0) { printf(" "); }
                printf("%d", treeNodes[path[i]].weight);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < treeNodes[root].children.size(); ++i) { // 递归遍历该节点下每一个子树
        int childNO = treeNodes[root].children[i];
        path.push_back(childNO);
        findPathOfEqualWeight(childNO, curWeightSum + treeNodes[childNO].weight, targetWeightSum);
        path.pop_back(); // 路径回溯法
    }
}

/**
 *
 * @param a
 * @param b
 * @return
 */
bool cmp(int a, int b) {
    return treeNodes[a].weight > treeNodes[b].weight;
}

int main() {
    int numberOfNode; // 节点总数
    int numberOfNonLeafNode; // 非叶子节点数
    int targetWeightSum; // 给定的权值之和
    scanf("%d%d%d", &numberOfNode, &numberOfNonLeafNode, &targetWeightSum);
    for (int i = 0; i < numberOfNode; ++i) {
        scanf("%d", &treeNodes[i].weight);
    }
    int nodeNO;
    int childNumberOfNode;
    int childNO;
    for (int i = 0; i < numberOfNonLeafNode; ++i) {
        scanf("%d%d", &nodeNO, &childNumberOfNode);
        for (int j = 0; j < childNumberOfNode; ++j) {
            scanf("%d", &childNO);
            treeNodes[nodeNO].children.push_back(childNO);
        }
        sort(treeNodes[nodeNO].children.begin(), treeNodes[nodeNO].children.end(), cmp);
    }

    path.push_back(0);
    findPathOfEqualWeight(0, treeNodes[0].weight, targetWeightSum);

    return 0;
}
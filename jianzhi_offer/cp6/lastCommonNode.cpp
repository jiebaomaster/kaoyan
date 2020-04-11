/*
 * P326 树中两个节点的最低公共祖先
 * 1. 若是一颗二叉排序树，可按如下方法：
 *      若当前节点的值比两个节点都小，则两个节点都在其左子树上，走左边
 *      若当前节点的值比两个节点都大，则两个节点都在其右子树上，走右边
 *      若当前节点的值在两个节点之间，则该节点就是最低公共祖先
 * 2. 若是一颗普通树，且每个节点有指向父节点的指针，则两个节点分别沿着的父节点直到根节点构成两个链表，问题转化为求这两个链表的第一个公共节点
 * 3. 若是一颗普通树，且每个节点没有指向父节点的指针，则可以记录从根到两个节点的遍历路径，其路径上的最后一个相同节点就是最低公共祖先
 * 此处编写第三种情况的代码
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct treeNode {
    int value;
    vector<treeNode *> pChildren;
} *Tree, TreeNode;

/**
 * 先序遍历树，找出到指定节点的路径
 * 在一个多路选择（图、矩阵、树）问题中寻找一条路径，通常可采用递归回溯法
 * @param pRoot
 * @param pNode
 * @param path 存放路径的 vector，这里要对其进行修改需要用引用类型
 * @return
 */
bool getNodePath(TreeNode *pRoot, TreeNode *pNode, vector<TreeNode *> &path) {
    if (pRoot == pNode) { return true; }

    path.push_back(pRoot); // 当前节点加入路径
    bool flag = false;
    for (vector<TreeNode *>::iterator it = pRoot->pChildren.begin(); it != pRoot->pChildren.end(); ++it) { // 递归遍历子树
        flag = getNodePath(*it, pNode, path);
        if (flag) { break; } // 子树中含有指定节点即可退出循环
    }

    if (!flag) { path.pop_back(); } // 子树中不包含指定节点，路径回溯

    return flag;
}

/**
 * 公共路径法获取最低公共祖先
 * @param T
 * @param pNode1
 * @param pNode2
 * @return
 */
TreeNode *getLastCommonNode(Tree T, TreeNode *pNode1, TreeNode *pNode2) {
    vector<TreeNode *> path1;
    getNodePath(T, pNode1, path1);
    vector<TreeNode *> path2;
    getNodePath(T, pNode2, path2);

    vector<TreeNode *>::iterator it1 = path1.begin();
    vector<TreeNode *>::iterator it2 = path2.begin();
    TreeNode *pLastCommonNode = NULL;
    while (it1 != path1.end() && it2 != path2.end()) { // 遍历两条路径
        if (*it1 == *it2) { pLastCommonNode = *it1; } // 两条路径中相同的节点赋值给结果指针，可知结果为最后一个相同节点
        it1++;
        it2++;
    }
    return pLastCommonNode;
}

/**
 * 新建一个节点
 * @param n
 * @return
 */
TreeNode *createNode(int n) {
    TreeNode *node = new TreeNode;
    node->value = n;
    return node;
}

int main() {
    TreeNode *p1 = createNode(1);
    TreeNode *p2 = createNode(2);
    TreeNode *p3 = createNode(3);
    TreeNode *p4 = createNode(4);
    TreeNode *p5 = createNode(5);
    TreeNode *p6 = createNode(6);
    TreeNode *p7 = createNode(7);
    p4->pChildren.push_back(p5);
    p4->pChildren.push_back(p6);
    p3->pChildren.push_back(p4);
    p2->pChildren.push_back(p7);
    p1->pChildren.push_back(p2);
    p1->pChildren.push_back(p3);

    TreeNode *p56 = getLastCommonNode(p1, p5, p6);
    TreeNode *p57 = getLastCommonNode(p1, p5, p7);
    TreeNode *p54 = getLastCommonNode(p1, p5, p4);

    cout << p56->value << ' ' << p57->value << ' ' << p54->value; // 4 1 3
}

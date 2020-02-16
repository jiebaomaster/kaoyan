#include <stdio.h>
#include <stdbool.h>

/**
 * P179 判断一个序列是否是二叉搜索树的后续遍历序列
 * 这个序列中的每一个数都不相同
 * 根据 BST 后序序列的特点，序列最后一个元素为根，其余元素从左到右先小于根（左子树）后大于根（右子树）
 * @param postOrder
 * @return
 */
bool isPostOrderOfBST(int *postOrder, int length) {
    if (length <= 0 || postOrder == NULL) { return false; }
    if (length == 1 || length == 2) { return true; }
    int rootValue = *(postOrder + length - 1); // 最后一个元素是根节点

    int *firstRightChildNode = NULL;
    for (int *p = postOrder; p - postOrder < length - 1; ++p) {
        if (*p > rootValue) {
            firstRightChildNode = p; // 找第一个比根大的元素，即右子树开始的地方
            break;
        }
    }
    if (firstRightChildNode) { // 若存在右子树，则在右子树中尝试寻找一个比根小的数，若存在则不是 BST 的后序序列
        for (int *pr = firstRightChildNode; pr - postOrder < length - 1; ++pr) {
            if (*pr < rootValue) {
                return false;
            }
        }
    }
    bool left = false;
    if (firstRightChildNode != postOrder) { // 判断左子树
        left = isPostOrderOfBST(postOrder, firstRightChildNode - postOrder);
    }
    bool right = false;
    if (firstRightChildNode) { // 判断右子树
        right = isPostOrderOfBST(firstRightChildNode, length - (firstRightChildNode - postOrder) - 1);
    }
    return left && right;
}

int main() {
    int data1[] = {5, 7, 6, 9, 11, 10, 8};
    int data2[] = {7, 4, 6, 5};

    printf("%d %d", isPostOrderOfBST(data1, 7), isPostOrderOfBST(data2, 4));

    return 0;
}
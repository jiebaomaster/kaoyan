/*
 * P273 判断二叉树是否是平衡二叉树。若树中任意节点的左右子树深度差不超过1，则称为平衡二叉树
 */

#include <stdio.h>
#include <stdbool.h>
#include "../lib/binaryTree/binaryTree.h"

/**
 * 后续遍历二叉树计算子树深度，在遍历过程中利用子树深度判断子树是否平衡
 * @param T
 * @param depth
 * @return
 */
bool isBalancedBinaryTreeCore(BinaryTree T, int *depth) {
    if (T == NULL) {
        *depth = 0;
        return true;
    }

    int lDepth, rDepth;
    if (isBalancedBinaryTreeCore(T->lChild, &lDepth) && isBalancedBinaryTreeCore(T->rChild, &rDepth)) { // 判断子节点是否平衡
        int diff = lDepth - rDepth;
        if (diff < 2 && diff > -2) { // 判断该节点是否平衡
            *depth = (lDepth > rDepth ? lDepth : rDepth) + 1; // 计算子树深度
            return true;
        }
    }
    return false;
}

/**
 * 判断二叉树是否是平衡二叉树
 * @param T
 * @return
 */
bool isBalancedBinaryTree(BinaryTree T) {
    int depth = 0;
    return isBalancedBinaryTreeCore(T, &depth);
}

int main() {
    int pre1[] = {1, 2, 4, 5, 7, 3, 6};
    int in1[] = {4, 2, 7, 5, 1, 3, 6};
    BinaryTree T1 = constructByPreOrderAndInOrder(pre1, in1, 7);

    int pre2[] = {1, 2, 3};
    int in2[] = {3, 2, 1};
    BinaryTree T2 = constructByPreOrderAndInOrder(pre2, in2, 3);

    printf("T1:%d T2:%d", isBalancedBinaryTree(T1), isBalancedBinaryTree(T2));

    return 0;
}

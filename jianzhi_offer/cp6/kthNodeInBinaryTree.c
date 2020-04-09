/*
 * P269 找出二叉搜索树中的第 k 小的节点
 */

#include <stdio.h>
#include "../lib/binaryTree/binaryTree.h"

/**
 * 中序遍历二叉搜索树
 * @param T
 * @param k
 * @return
 */
BinaryTreeNode *findKthNodeCore(BinaryTree T, int *k) {
    if (T == NULL) { return NULL; }
    BinaryTreeNode *node = findKthNodeCore(T->lChild, k);
    if (node == NULL) {
        if (*k == 1) {
            node = T;
        }
        *k = (*k) - 1;
    }
    if (node == NULL) {
        node = findKthNodeCore(T->rChild, k);
    }
    return node;
}

BinaryTreeNode *findKthNode(BinaryTree T, int k) {
    if (T == NULL || k <= 0) { return NULL; }
    return findKthNodeCore(T, &k);
}

int main() {
    int pre[] = {5, 3, 2, 4, 7, 6, 8};
    int in[] = {2, 3, 4, 5, 6, 7, 8};
    BinaryTree T = constructByPreOrderAndInOrder(pre, in, 7);
    printf("%d", findKthNode(T, 3)->value);

    return 0;
}

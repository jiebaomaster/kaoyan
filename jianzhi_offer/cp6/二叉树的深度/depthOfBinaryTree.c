/*
 * P271 获取二叉树的深度
 */

#include <stdio.h>
#include "../../lib/binaryTree/binaryTree.h"

/**
 * 获取二叉树的深度
 * @param T
 * @return
 */
int getDepth(BinaryTree T) {
    if (T == NULL) { return 0; }
    else {
        int lDepth = getDepth(T->lChild);
        int rDepth = getDepth(T->rChild);
        return (lDepth > rDepth ? lDepth : rDepth) + 1; // 选择左右子树中深度大的+1
    }
}

int main() {
    int pre[] = {1, 2, 4, 5, 7, 3, 6};
    int in[] = {4, 2, 7, 5, 1, 3, 6};
    BinaryTree T = constructByPreOrderAndInOrder(pre, in, 7);
    printf("%d", getDepth(T));

    return 0;
}


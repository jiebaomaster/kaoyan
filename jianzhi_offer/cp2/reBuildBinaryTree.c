#include <stdio.h>
#include "../lib/binaryTree/binaryTree.h"

// P62 根据先序遍历和中序遍历生成二叉树

int main() {
    BinaryTree T = NULL;
    int preOrderList[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrderList[] = {4, 7, 2, 1, 5, 3, 8, 6};

    T = constructByPreOrderAndInOrder(preOrderList, inOrderList, 8);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);

    return 0;
}
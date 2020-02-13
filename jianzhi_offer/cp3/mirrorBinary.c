#include <stdio.h>
#include "../lib/binaryTree/binaryTree.h"

void mirrorBinary(BinaryTree T) {
    if (T == NULL) { return; }

    BinaryTree pTree = T->lChild;
    T->lChild = T->rChild;
    T->rChild = pTree;
    mirrorBinary(T->lChild);
    mirrorBinary(T->rChild);
}

int main() {
    BinaryTree T1 = NULL;
    int preOrderListT1[] = {3, 8, 9, 2, 4, 7, 6};
    int inOrderListT1[] = {9, 8, 4, 2, 7, 3, 6};
    T1 = constructByPreOrderAndInOrder(preOrderListT1, inOrderListT1, 7);

    mirrorBinary(T1);
    preOrder(T1);
    printf("\n");
    inOrder(T1);

    return 0;
}
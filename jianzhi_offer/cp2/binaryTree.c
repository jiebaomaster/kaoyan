#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

// 递归
void preOrder(BinaryTree T) {
    if (T != NULL) {
        printf("%d", T->value);
        preOrder(T->lChild);
        preOrder(T->rChild);
    }
}

void inOrder(BinaryTree T) {
    if (T != NULL) {
        inOrder(T->lChild);
        printf("%d", T->value);
        inOrder(T->rChild);
    }

}

void postOrder(BinaryTree T) {
    if (T != NULL) {
        postOrder(T->lChild);
        postOrder(T->rChild);
        printf("%d", T->value);
    }
}

/**
 * 递归建立二叉树
 * @param startPreOrder
 * @param endPreOrder
 * @param startInOrder
 * @param endInOrder
 * @return
 */
BinaryTree constructChildTree(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder) {
    BinaryTreeNode *treeNode = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    treeNode->lChild = NULL;
    treeNode->rChild = NULL;
    treeNode->value = startPreOrder[0];

    if (startInOrder != endInOrder) { // 单元素的情况直接输出节点
        int *rootInOrder = startInOrder; // 根节点元素的指针在中序遍历结果中的位置指针
        int *leftEndPreOrder = startPreOrder;
        while (*rootInOrder != *startPreOrder) { // 在中序遍历结果中寻找根节点的位置
            rootInOrder++;
            leftEndPreOrder++;
            if (rootInOrder == endInOrder && *rootInOrder != *endInOrder) {
                printf("输入数据有误，不能构成二叉树");
                return NULL;
            }
        }
        if (*rootInOrder != *startInOrder) {
            treeNode->lChild = constructChildTree(startPreOrder + 1, leftEndPreOrder, startInOrder, rootInOrder - 1);
        }
        if (*rootInOrder != *endInOrder) {
            treeNode->rChild = constructChildTree(leftEndPreOrder + 1, endPreOrder, rootInOrder + 1, endInOrder);
        }
    }
    return treeNode;
}

BinaryTree constructByPreOrderAndInOrder(int *preOrder, int *inOrder, int length) {
    if (preOrder == NULL || inOrder == NULL || length <= 0) {
        return NULL;
    } else {
        return constructChildTree(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
    }
}
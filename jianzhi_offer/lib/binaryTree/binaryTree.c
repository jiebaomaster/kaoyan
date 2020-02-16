#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "../queue/queue.h"

// 递归
void preOrder(BinaryTree T) {
    if (T != NULL) {
        printf("%d ", T->value);
        preOrder(T->lChild);
        preOrder(T->rChild);
    }
}

void inOrder(BinaryTree T) {
    if (T != NULL) {
        inOrder(T->lChild);
        printf("%d ", T->value);
        inOrder(T->rChild);
    }

}

void postOrder(BinaryTree T) {
    if (T != NULL) {
        postOrder(T->lChild);
        postOrder(T->rChild);
        printf("%d ", T->value);
    }
}

void levelOrder(BinaryTree T) {
    if (T == NULL) { return; }
    LinkQueue Q;
    initQueue(&Q);
    enQueue(&Q, T);

    BinaryTreeNode *pNode = NULL;
    while (deQueue(&Q, (void **) &pNode)) {
        printf("%d ", pNode->value);
        if (pNode->lChild) {
            enQueue(&Q, pNode->lChild);
        }
        if (pNode->rChild) {
            enQueue(&Q, pNode->rChild);
        }
    }
}

/**
 * 新建一个树节点
 * @param value
 * @return
 */
BinaryTreeNode *creatNewBinaryNode(int value) {
    BinaryTreeNode *treeNode = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    treeNode->lChild = NULL;
    treeNode->rChild = NULL;
    treeNode->value = value;
    return treeNode;
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

BinaryTree constructByLayoutOrder(int *layoutOrder, int length) {
    if (layoutOrder == NULL || length <= 0 || layoutOrder[0] == NULL_NODE_VALUE) { return NULL; }

    BinaryTreeNode *root = creatNewBinaryNode(layoutOrder[0]);
    LinkQueue Q;
    initQueue(&Q);
    enQueue(&Q, root);

    int i = 1;
    while (i < length) {
        BinaryTreeNode *pNode = NULL;
        deQueue(&Q, (void **) &pNode);
        if (layoutOrder[i] != NULL_NODE_VALUE) {
            BinaryTreeNode *pLNode = creatNewBinaryNode(layoutOrder[i]);
            enQueue(&Q, pLNode);
            pNode->lChild = pLNode;
        }
        i++;
        if (i < length && layoutOrder[i] != NULL_NODE_VALUE) {
            BinaryTreeNode *pRNode = creatNewBinaryNode(layoutOrder[i]);
            enQueue(&Q, pRNode);
            pNode->rChild = pRNode;
        }
        i++;
    }

    return root;
}

// 功能测试
//int main() {
//    // constructByLayoutOrder
//    int data[] = {1, 2, 3, 4, NULL_NODE_VALUE, 5, NULL_NODE_VALUE, NULL_NODE_VALUE, 6, NULL_NODE_VALUE, 7, 8, 9,
//                  NULL_NODE_VALUE, 10};
//    BinaryTree T = constructByLayoutOrder(data, 15);
//    preOrder(T);
//    printf("\n");
//    levelOrder(T);
//}
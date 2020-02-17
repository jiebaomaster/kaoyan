#include <stdio.h>
#include "../lib/binaryTree/binaryTree.h"

/**
 * 递归转化每一个节点
 * @param pNode
 * @param pListHead
 * @param pListTail
 */
void convertNodeCore(BinaryTreeNode *pNode, BinaryTreeNode **pListHead, BinaryTreeNode **pListTail) {
    if (pNode == NULL) { return; }

    // 将左右节点转化为双向链表
    BinaryTreeNode *pLChildHead = pNode;
    BinaryTreeNode *pLChildTail = pNode;
    BinaryTreeNode *pRChildHead = pNode;
    BinaryTreeNode *pRChildTail = pNode;
    convertNodeCore(pNode->lChild, &pLChildHead, &pLChildTail);
    convertNodeCore(pNode->rChild, &pRChildHead, &pRChildTail);
    // 将根节点接在左右链表之间
    pLChildTail->rChild = pNode;
    pNode->lChild = pLChildTail;
    pNode->rChild = pRChildHead;
    pRChildHead->lChild = pNode;
    // 更新根节点加入后双向链表的头尾指针
    *pListHead = pLChildHead;
    *pListTail = pRChildTail;
}

/**
 * P191 将二叉搜索树转化为双向链表
 * @param T
 * @return
 */
BinaryTreeNode *convertBST2TwoWayList(BinaryTree T) {
    BinaryTreeNode *pListHead = NULL,
            *pListTail = NULL;
    convertNodeCore(T, &pListHead, &pListTail);
    pListHead->lChild = NULL;
    pListTail->rChild = NULL;
    return pListHead;
}

int main() {
    int data[] = {10, 6, 14, 4, 8, 12, 16};
    BinaryTree T = constructByLayoutOrder(data, 7);
    BinaryTreeNode *listHead = convertBST2TwoWayList(T);

    while (listHead != NULL) {
        printf("%d ", listHead->value);
        listHead = listHead->rChild;
    }
    return 0;
}
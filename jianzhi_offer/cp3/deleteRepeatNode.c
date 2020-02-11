#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/list/list.h"

/**
 * P124 删除链表中元素连续重复的节点
 * @param pL
 * @return
 */
void deleteRepeatNode(LinkList *pL) {
    ListNode *pNode = *pL;
    ListNode *pPreNode = NULL;
    while (pNode != NULL) {
        ListNode *pNextNode = pNode->next;
        if (pNextNode != NULL && pNode->value == pNextNode->value) { // 下一个元素不一定存在，需要先判断
            ListNode *pToBeDelNode = pNode; // 标记当前元素为第一个需要删除的元素
            int value = pNode->value; // pNode 会被删除，需要先记录其值
            while (pToBeDelNode != NULL && pToBeDelNode->value == value) { // 从第一个待删除元素开始依次删除
                pNextNode = pToBeDelNode->next;
                free(pToBeDelNode);
                pToBeDelNode = pNextNode;
            }
            if (pPreNode) {
                pPreNode->next = pNextNode;
            } else { // 前序元素为null，即从第一个元素开始被删除，需要重新修正前序元素的指向
                *pL = pToBeDelNode;
            }
        } else {
            pPreNode = pNode; // 移动前序元素
        }
        pNode = pNextNode;
    }
}

int main() {
    int listNodeData1[] = {2, 2, 2, 2};
    LinkList L1 = NULL;
    initListByArray(&L1, listNodeData1, 4);
    listPrint(L1);
    printf("\n");
    deleteRepeatNode(&L1);
    listPrint(L1);
    printf("\n");

    int oneNodeList[] = {1, 1, 2, 3, 4, 4, 5, 6, 6};
    LinkList L2 = NULL;
    initListByArray(&L2, oneNodeList, 9);
    listPrint(L2);
    printf("\n");
    deleteRepeatNode(&L2);
    listPrint(L2);

    return 0;
}



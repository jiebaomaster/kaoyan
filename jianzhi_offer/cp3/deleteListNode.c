#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../lib/list/list.h"

/**
 * P119 在 O(1) 的时间内删除链表中的一个节点
 * @param L
 * @param pToBeDelete 待删除节点的指针
 * @return
 */
bool deleteListNode(LinkList *L, ListNode *pToBeDelete) {
    if (L == NULL || pToBeDelete == NULL) { return false; }

    if (pToBeDelete->next != NULL) { // 当前节点不是最后一个节点
        ListNode *pNext = pToBeDelete->next;
        pToBeDelete->value = pNext->value;
        pToBeDelete->next = pNext->next;

        free(pNext); // 删除p的下一个节点
        pNext = NULL;
    } else if (*L == pToBeDelete) { // 只有一个节点，删除当前节点
        free(pToBeDelete);
        pToBeDelete = NULL;
        *L = NULL;
    } else { // 有多个节点，删除尾节点，只能使用传统方法
        ListNode *pPre = *L;
        while (pPre->next != pToBeDelete) pPre = pPre->next; // 寻找前序节点
        pPre->next = NULL;
        free(pToBeDelete);
        pToBeDelete = NULL;
    }
    return true;
}

int main() {
    int listNodeData[] = {1, 2, 3, 4, 5};
    LinkList L = NULL;
    initListByArray(&L, listNodeData, 5);
    listPrint(L);
    printf("\n");
    deleteListNode(&L, L->next);
    listPrint(L);
    printf("\n");

    int listNodeData1[] = {1, 2, 3};
    LinkList L1 = NULL;
    initListByArray(&L1, listNodeData1, 3);
    listPrint(L1);
    printf("\n");
    deleteListNode(&L1, L1->next->next);
    listPrint(L1);
    printf("\n");

    int oneNodeList[] = {1};
    LinkList L2 = NULL;
    initListByArray(&L2, oneNodeList, 1);
    listPrint(L2);
    printf("\n");
    deleteListNode(&L2, L2);
    listPrint(L2);

    return 0;
}
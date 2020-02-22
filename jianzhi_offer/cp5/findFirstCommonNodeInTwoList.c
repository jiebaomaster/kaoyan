#include <stdio.h>
#include "../lib/list/list.h"

int getLinkListLength(LinkList L) {
    ListNode *pNode = L;
    int count = 0;
    while (pNode != NULL) {
        pNode = pNode->next;
        count++;
    }
    return count;
}

/**
 * P253 寻找两个链表的第一个公共节点
 * @param L1
 * @param L2
 * @return
 */
ListNode *findFirstCommonNode(LinkList L1, LinkList L2) {
    if (L1 == NULL || L2 == NULL) { return NULL; }

    int listLength1 = getLinkListLength(L1);
    int listLength2 = getLinkListLength(L2);
    int lengthDif = listLength1 - listLength2;
    ListNode *pLongList = L1;
    ListNode *pShortList = L2;
    if (lengthDif < 0) {
        pLongList = L2;
        pShortList = L1;
        lengthDif = -lengthDif;
    }

    // 先在长的链表中多走几步，再两个链表同时走，直到碰到第一个公共节点
    while (lengthDif--) { pLongList = pLongList->next; }
    while (pLongList != NULL && pShortList != NULL) {
        if (pLongList == pShortList) {
            return pLongList;
        }
        pLongList = pLongList->next;
        pShortList = pShortList->next;
    }
    printf("不存在相同的节点!\n");
    return NULL;
}

int main() {
    LinkList L1 = NULL, L2 = NULL;
    int data1[] = {1, 2, 3, 4};
    int data2[] = {5, 6, 7};
    initListByArray(&L1, data1, 4);
    initListByArray(&L2, data2, 3);
    findFirstCommonNode(L1, L2);

    L2->next->next->next = L1->next->next; // L2:7->3
    ListNode *pNode = findFirstCommonNode(L1, L2);
    printf("%d", pNode->value);

    return 0;
}
#include <stdio.h>
#include "../lib/list/list.h"

/**
 * P145 合并两个递增排序的链表，使合并后链表仍然使递增的
 * @param L1
 * @param L2
 * @return
 */
ListNode *mergeOrderList(LinkList L1, LinkList L2) {
    ListNode *pL1 = L1;
    ListNode *pL2 = L2;
    ListNode *pTailNode = NULL;
    ListNode *pHeadNode = NULL;
    while (pL1 != NULL || pL2 != NULL) {
        if (pTailNode) { // 计算第一个节点时，pTailNode 为 NULL
            pTailNode = pTailNode->next;
        }
        if (pL1 == NULL) {
            pTailNode = pL2;
            break;
        } else if (pL2 == NULL) {
            pTailNode = pL1;
            break;
        } else {
            if (pL1->value >= pL2->value) {
                pTailNode = pL2;
                pL2 = pL2->next;
            } else {
                pTailNode = pL1;
                pL1 = pL1->next;
            }
        }
        if (!pHeadNode) {
            pHeadNode = pTailNode;
        }
    }
    return pHeadNode;
}

/**
 * 递归方式合并链表
 * @param L1
 * @param L2
 * @return
 */
ListNode *mergeOrderListRecursively(LinkList L1, LinkList L2) {
    if (L1 == NULL) { return L2; }
    else if (L2 == NULL) { return L1; }
    else {
        ListNode *pNode = NULL;
        if (L1->value >= L2->value) {
            pNode = L2;
            pNode->next = mergeOrderListRecursively(L1, L2->next);
        } else {
            pNode = L1;
            pNode->next = mergeOrderListRecursively(L1->next, L2);
        }
        return pNode;
    }
}

int main() {
    int dataOdd[4] = {1, 3, 5, 7};
    LinkList L1 = NULL;
    initListByArray(&L1, dataOdd, 4);

    int dataEven[4] = {2, 4, 6, 8};
    LinkList L2 = NULL;
    initListByArray(&L2, dataEven, 4);

    LinkList L3 = mergeOrderListRecursively(L1, L2);
    listPrint(L3);
    printf("\n");
    LinkList L4 = mergeOrderList(L1, L2);
    listPrint(L4);

    return 0;
}
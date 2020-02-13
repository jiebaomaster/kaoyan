#include <stdio.h>
#include "../lib/list/list.h"

/**
 * P142 反转链表
 * @param pL
 */
void reverseList(LinkList *pL) {
    if (pL == NULL || (*pL)->next == NULL) { return; } //

    ListNode *pPreNode = NULL;
    ListNode *pNode = *pL;
    ListNode *pNextNode = *pL;
    while (pNode) {
        pNextNode = pNextNode->next;
        pNode->next = pPreNode;
        pPreNode = pNode;
        pNode = pNextNode;
    }
    *pL = pPreNode;
}

/**
 * 递归反转
 * @param L
 * @param pPreNode
 * @return
 */
ListNode *reverseListRecursivelyCore(LinkList L, ListNode *pPreNode) {
    if (L == NULL) { return pPreNode; } // 将链表尾元素沿递归传递
    ListNode *pHeadNode = reverseListRecursivelyCore(L->next, L);
    L->next = pPreNode;
    return pHeadNode;
}

/**
 * 使用递归方法反转链表
 * @param pL
 */
void reverseListRecursively(LinkList *pL) {
    if (pL == NULL || (*pL)->next == NULL) { return; }
    *pL = reverseListRecursivelyCore(*pL, NULL);
}

int main() {
    int data[6] = {1, 2, 3, 4, 5, 6};
    LinkList L;
    initListByArray(&L, data, 6);
    listPrint(L);
    reverseList(&L);
    listPrint(L);
    reverseListRecursively(&L);
    listPrint(L);
    return 0;
}
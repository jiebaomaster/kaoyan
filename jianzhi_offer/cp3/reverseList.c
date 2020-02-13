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

int main() {
    int data[6] = {1, 2, 3, 4, 5, 6};
    LinkList L;
    initListByArray(&L, data, 6);
    listPrint(L);
    reverseList(&L); // 在无环的链表中查找
    listPrint(L);

    return 0;
}
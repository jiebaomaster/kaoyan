#include <stdio.h>
#include <stdbool.h>
#include "../lib/list/list.h"

/**
 * 判断链表里是否有环
 * 快慢指针，快指针一次走一步，慢指针一次走两步，
 *   若有环，则最终快指针会等于慢指针，共同指向链表中的一个节点，用 p 返回该指针
 *   若无环，则快指针会先走到链表尾，此时快指针指向 NULL
 * @param L
 * @param p
 * @return
 */
bool hasLoopInList(LinkList L, ListNode **p) {
    if (L == NULL) { return false; }

    ListNode *pFast = L;
    ListNode *pLow = L;
    do {
        pFast = pFast->next;
        if (pFast == NULL) { break; } // 若无环，快指针先走到表尾
        else {
            pFast = pFast->next; // 快指针走两步
        }
        pLow = pLow->next; // 慢指针走一步
    } while (pFast != NULL && pFast != pLow);

    if (pFast == NULL) {
        printf("错误！此链表中没有环。");
        return false;
    } else {
        *p = pFast;
        return true;
    }
}

/**
 * P139 寻找链表中环的入口节点
 * @param L
 * @return
 */
ListNode *findEntryNodeOfLoop(LinkList L) {
    // 先判断链表里是否有环
    ListNode *pNode = NULL;
    if (!hasLoopInList(L, &pNode) || pNode == NULL) { return NULL; }

    /**
     * 计算环里总共包含几个节点
     * 从环里的某个节点出发，依次向后遍历并计数，再次回到该节点时可得
     */
    ListNode *pTravel = pNode->next;
    int count = 1;
    while (pTravel != pNode) {
        pTravel = pTravel->next;
        count++;
    }

    /**
     * 快慢指针，快指针先走 count 步，然后两个指针以相同速度向前移动
     * 则当慢指针指向环入口节点时，快指针已经围绕着环走了一圈，又回到了入口节点
     */
    ListNode *pLow = L;
    ListNode *pFast = L;
    for (int i = 0; i < count; ++i) { // 快指针先走
        pFast = pFast->next;
    }
    while (pFast != pLow) { // 快慢一起走
        pFast = pFast->next;
        pLow = pLow->next;
    }
    return pLow;
}


int main() {
    int data[6] = {1, 2, 3, 4, 5, 6};
    LinkList L;
    initListByArray(&L, data, 6);
    listPrint(L);
    findEntryNodeOfLoop(L); // 在无环的链表中查找

    ListNode *pNode = L;
    while (pNode->next != NULL) { pNode = pNode->next; }
    pNode->next = L->next->next->next->next->next; // 将尾节点的下一个节点指向第三个节点，即环入口为第三个节点
    ListNode *pEntryNodeOfLoop = findEntryNodeOfLoop(L); // 在有环的链表中查找
    printf("\n%d", pEntryNodeOfLoop->value);

    return 0;
}
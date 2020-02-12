#include <stdio.h>
#include "../lib/list/list.h"

/**
 * P134 寻找链表中倒数第 k 个节点
 * @param L
 * @param k
 * @return
 */
ListNode *findKthToTail(LinkList L, int k) {
    if (L == NULL || k <= 0) {
        printf("参数错误");
        return NULL;
    }
    ListNode *pFast = L;
    ListNode *pLow = L;
    // 快指针先走 k-1 步，慢指针再走，当快指针到链表尾的时候慢指针正好走到倒数第 k 个
    while (pFast->next != NULL) {
        if (k == 1) {
            pLow = pLow->next;
        } else {
            k--;
        }
        pFast = pFast->next;
    }
    if (k == 1) {
        return pLow;
    } else {
        printf("错误输入，没有倒数第k个节点");
        return NULL;
    }
}

int main() {
    int data[6] = {1, 2, 3, 4, 5, 6};
    LinkList L;
    initListByArray(&L, data, 6);
    listPrint(L);
    ListNode *pNode = findKthToTail(L, 2);
    printf("\n%d\n", pNode->value);
    findKthToTail(L, 10);

    return 0;
}
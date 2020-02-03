#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * 在链表尾部插入一个节点
 * @param L
 * @param value
 */
void addToTail(LinkList *L, int value) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    ListNode *p = *L;
    if (p == NULL) {
        *L = node;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = node;
    }
}

/**
 * 用一个数组初始化一个链表
 * @param L
 * @param values
 * @param length
 */
void initListByArray(LinkList *L, int values[], int length) {
    if (values == NULL || length <= 0) { return; }
    else {
        for (int i = 0; i < length; ++i) {
            addToTail(L, values[i]);
        }
    }

}

/**
 * 顺序遍历链表
 * @param L
 */
void listPrint(LinkList L) {
    if (L == NULL) { return; }
    else {
        ListNode *p = L;
        while (p) {
            printf("%d", p->value);
            p = p->next;
        }
    }
}

/**
 * 逆序遍历链表，用递归模拟栈
 * @param L
 */
void listReversePrint(LinkList L) {
    if (L != NULL) {
        listReversePrint(L->next);
        printf("%d", L->value);
    }
}
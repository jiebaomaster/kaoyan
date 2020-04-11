/*
 * P300 约瑟夫环问题，0～n-1 这 n 个数排成一个圆圈，从数字0开始，每次从这个圆圈里删除第 m 个数字，求最后剩下的数字
 * 用循环链表模拟运算过程解决
 */

#include <stdio.h>
#include <stdlib.h>
#include "../lib/list/list.h"

const int maxn = 10010;
int data[maxn];

/**
 * 用循环链表模拟运算过程解决约瑟夫环问题
 * @param n 环的长度
 * @param m 每次删除的数字次序
 * @return
 */
int getLastRemaining(int n, int m) {
    // 构造循环链表
    LinkList L;
    initListByArray(&L, data, n);
    ListNode *p = L;
    while (p->next != NULL) { p = p->next; }
    p->next = L;

    p = L; // 从 0 开始
    while (p->next != p) { // 模拟运算，直到只剩一个元素为止
        int i = m;
        while (--i) { p = p->next; } // 找到要删除的节点
        // 原地删除指定节点
        ListNode *next = p->next;
        p->value = next->value;
        p->next = next->next;
        free(next);
    }
    return p->value;
}

int main() {
    for (int i = 0; i < maxn; ++i) { // 初始化
        data[i] = i;
    }
    printf("%d", getLastRemaining(5, 3));
}
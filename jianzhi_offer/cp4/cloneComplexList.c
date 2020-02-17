#include <stdio.h>
#include <stdlib.h>

typedef struct ComplexListNode { // 复杂链表节点
    int value; // 元素值
    struct ComplexListNode *pNext; // 下一个元素
    struct ComplexListNode *pSibling; // 链表中的任意一个元素
} ComplexListNode, *ComplexList;

/**
 * P187 复制复杂链表
 * @param complexList
 * @return
 */
ComplexList cloneComplexList(ComplexList complexList) {
    if (complexList == NULL) { return NULL; }
    ComplexListNode *pNode = complexList;
    while (pNode != NULL) { // 在每个节点之后插入一个复制节点，如：A -> A' -> B -> B' -> NULL
        ComplexListNode *complexListNode = (ComplexListNode *) malloc(sizeof(ComplexListNode));
        complexListNode->value = pNode->value;
        complexListNode->pNext = pNode->pNext;
        complexListNode->pSibling = NULL;

        pNode->pNext = complexListNode;
        pNode = complexListNode->pNext;
    }

    pNode = complexList;
    while (pNode != NULL) { // 给复制的节点建立 Sibling 关系，复制节点的兄弟节点在原节点的兄弟节点之后
        ComplexListNode *pCloneNode = pNode->pNext;
        if (pNode->pSibling != NULL) {
            pCloneNode->pSibling = pNode->pSibling->pNext;
        }
        pNode = pCloneNode->pNext;
    }

    ComplexList cloneList = NULL;
    ComplexListNode *pCloneListTail = NULL; // 指向复制的链表最后一个节点的指针
    // 第一个节点预处理
    pNode = complexList;
    cloneList = pCloneListTail = pNode->pNext;
    pNode->pNext = pCloneListTail->pNext;
    pNode = pNode->pNext;
    while (pNode != NULL) { // 把复制链表的节点从原节点中摘除，只需要处理 next 指针
        pCloneListTail->pNext = pNode->pNext;
        pCloneListTail = pCloneListTail->pNext;
        pNode->pNext = pCloneListTail->pNext;
        pNode = pNode->pNext;
    }
    return cloneList;
}

int main() {
    int data[] = {5, 4, 4, 3, 2, 1};
    ComplexList complexList = NULL;
    for (int i = 0; i < 6; ++i) { // 头插法建立链表
        ComplexListNode *complexListNode = (ComplexListNode *) malloc(sizeof(ComplexListNode));
        complexListNode->value = data[i];
        complexListNode->pNext = complexList;
        complexListNode->pSibling = NULL;
        complexList = complexListNode;
    }
    complexList->pSibling = complexList->pNext->pNext; // 1->3
    complexList->pNext->pNext->pNext->pSibling = complexList->pNext; // 4->2

    ComplexList cloneList = cloneComplexList(complexList);
    return 0;
}




#include <stdio.h>
#include "list.h"

// P58 从尾到头打印链表

int main() {
    int listNodeData[] = {1,2,3,4,5};
    LinkList L = NULL;
    initListByArray(&L, listNodeData, 5);
    listPrint(L);
    listReversePrint(L);
}
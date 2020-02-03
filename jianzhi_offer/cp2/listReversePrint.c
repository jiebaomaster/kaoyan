#include <stdio.h>
#include "list.h"

int main() {
    int listNodeData[] = {1,2,3,4,5};
    LinkList L = NULL;
    initListByArray(&L, listNodeData, 5);
    listPrint(L);
    listReversePrint(L);
}
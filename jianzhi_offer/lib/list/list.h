typedef struct ListNode { // 单链表
    int value; // 元素值
    struct ListNode *next; // 下一个节点的指针
} ListNode, *LinkList;

void addToTail(LinkList *L, int value);

void initListByArray(LinkList *L, int values[], int length);

void listPrint(LinkList L);

void listReversePrint(LinkList L);
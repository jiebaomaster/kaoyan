#include <stdbool.h>

typedef struct ListNode { // 链表节点
    void *value; // 元素值，void* 可支持任何数据类型
    struct ListNode *next; // 下一个节点的指针
} ListNode;

/**
 * 带头节点的链式队列
 * @property front 指向头节点的指针
 * @property rear 指向最后一个尾节点的指针
 */
typedef struct {
    ListNode *front, *rear;
} LinkQueue;

/**
 * 初始化链式队列
 * @param Q
 */
void initQueue(LinkQueue *Q);

/**
 * 判空
 * @param Q
 * @return
 */
bool isEmpty(LinkQueue Q);

/**
 * 元素入队尾
 * @param Q
 * @param pValue
 */
void enQueue(LinkQueue *Q, void* pValue);

/**
 * 队首元素出队
 * @param Q
 * @param pDelNodeValue
 * @return
 */
bool deQueue(LinkQueue *Q, void **pDelNodeValue);


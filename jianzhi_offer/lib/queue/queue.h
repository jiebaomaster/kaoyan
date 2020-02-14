#include <stdbool.h>
#include "../list/list.h"

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
 * @param value
 */
void enQueue(LinkQueue *Q, int value);

/**
 * 队首元素出队
 * @param Q
 * @return
 */
bool deQueue(LinkQueue *Q, int *delNodeValue);


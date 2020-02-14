#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * 初始化链式队列
 * @param Q
 */
void initQueue(LinkQueue *Q) {
    Q->rear = Q->front = (ListNode *) malloc(sizeof(ListNode)); // 建立头节点
    Q->front->value = NULL;
    Q->rear->next = NULL;
}

/**
 * 判空
 * @param Q
 * @return
 */
bool isEmpty(LinkQueue Q) {
    return Q.rear == Q.front;
}

/**
 * 元素入队尾
 * @param Q
 * @param pValue
 */
void enQueue(LinkQueue *Q, void *pValue) {
    ListNode *pNode = (ListNode *) malloc(sizeof(ListNode)); // 创建新节点
    pNode->value = pValue;
    pNode->next = NULL;

    Q->rear->next = pNode; // 插入新节点
    Q->rear = Q->rear->next;
}

/**
 * 队首元素出队
 * @param Q
 * @param pDelNodeValue
 * @return
 */
bool deQueue(LinkQueue *Q, void **pDelNodeValue) {
    if (isEmpty(*Q)) { return false; } // 空队不可出队

    ListNode *pNodeToDel = Q->front->next;
    *pDelNodeValue = pNodeToDel->value; // 记录被删除节点的值
    Q->front->next = pNodeToDel->next;
    if (Q->rear == pNodeToDel) { Q->rear = Q->front; } // 当队列中只有一个元素的时候，删除后要修改队尾指针，否则队尾指针会变成野指针
    free(pNodeToDel);

    return true;
}

// 测试基本功能
//int main() {
//    LinkQueue Q;
//    initQueue(&Q);
//    int data[] = {1};
//    enQueue(&Q, &data[0]);
//    int *result = NULL;
//    deQueue(&Q, (void **) &result);
//    enQueue(&Q, &data[0]);
//    enQueue(&Q, &data[0]);
//    deQueue(&Q, (void **) &result);
//}
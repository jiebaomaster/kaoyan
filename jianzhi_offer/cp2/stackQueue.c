#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/stack/stack.h"

typedef struct {
    Stack *S1;
    Stack *S2;
} CQueue;

/**
 * 入队尾
 * @param Q
 * @param value
 * @return
 */
bool appendTail(CQueue *Q, int value) {
    if (!Q) { return false; }
    push(Q->S1, value);
    return true;
}

/**
 * 队头元素出队
 * @param Q
 * @param value
 * @return
 */
bool deleteHead(CQueue *Q, int *value) {
    if (!Q) { return false; }
    if (isStackEmpty(*Q->S2)) {
        if (isStackEmpty(*Q->S1)) {
            return false;
        } else {
            int temp = 0;
            while (!isStackEmpty(*Q->S1)) {
                pop(Q->S1, &temp);
                push(Q->S2, temp);
            }
            pop(Q->S2, value);
        }
    } else {
        pop(Q->S2, value);
    }
    return true;
}

/**
 * 初始化队列
 * @param Q
 */
void InitCQueue(CQueue *Q) {
    Stack *S1 = (Stack *) malloc(sizeof(Stack)),
            *S2 = (Stack *) malloc(sizeof(Stack));
    InitStack(S1);
    InitStack(S2);
    Q->S1 = S1;
    Q->S2 = S2;
}

int main() {
    CQueue *Q = (CQueue *) malloc(sizeof(CQueue));
    InitCQueue(Q);

    int testData[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        appendTail(Q, testData[i]);
    }
    for (int i = 0; i < 5; ++i) {
        int tmp = 0;
        deleteHead(Q, &tmp);
        printf("%d", tmp);
    }
    return 0;
}

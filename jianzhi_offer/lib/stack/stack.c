#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

void InitStack(Stack *S) {
    S->data = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S->data) { exit(0); } // 内存分配失败
    S->top = S->data;
    S->stack_size = STACK_INIT_SIZE;
}

bool isStackEmpty(Stack S) {
    return S.top == S.data;
}


bool push(Stack *S, ElemType value) {
    if (S->top - S->data >= S->stack_size) { // 栈满追加分配内存
        S->data = (ElemType *) realloc(S->data, STACK_INCREMENT_SIZE * sizeof(ElemType));
        if (!S->data) { exit(0); } // 内存分配失败
        S->stack_size += STACK_INCREMENT_SIZE;
    }
    *S->top++ = value;
    return true;
}

bool pop(Stack *S, ElemType *value) {
    if (S->top == S->data) { return false; }
    ElemType top = *--S->top;
    if (value != NULL) { // 支持 value 传 NULL，即不需要获取栈顶值
        *value = top;
    }
    return true;
}

bool getTop(Stack S, ElemType *value) {
    if (S.top == S.data) { return false; }
    *value = *(S.top - 1);
    return true;
}

// 测试基本功能
//int main() {
//    int stackData[] = {1, 2, 3, 4, 5, 6, 7};
//    Stack S;
//    InitStack(&S);
//
//    for (int i = 0; i < 7; ++i) {
//        push(&S, stackData[i]);
//    }
//    int topValue = -1;
//    getTop(S, &topValue);
//
//    int stackDataPop[] = {0, 0, 0, 0, 0, 0, 0};
//    for (int i = 0; i < 7; ++i) {
//        pop(&S, &stackDataPop[i]);
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/stack/stack.h"

/**
 * P165 定义一种数据栈，可以在 O(1) 时间内得到栈中元素的最小值
 */
typedef struct {
    Stack *pData; // 数据栈
    Stack *pMin; // 数据栈中最小值辅助栈
} StackWithMin;

/**
 * 初始化
 * @param S
 */
void initStackWithMin(StackWithMin *S) {
    S->pData = (Stack *) malloc(sizeof(Stack));
    S->pMin = (Stack *) malloc(sizeof(Stack));
    InitStack(S->pData);
    InitStack(S->pMin);
}

/**
 * 压栈
 * @param S
 * @param value
 * @return
 */
bool stackMinPush(StackWithMin *S, int value) {
    if (S == NULL) { return false; }

    int curMin = value; // 当前栈中的最小值
    getTop(*S->pMin, &curMin); // 若辅助栈为空，则 curMin 不会被赋值，将 value 压入最小值栈
    push(S->pMin, curMin > value ? value : curMin); // 辅助栈里压入 min{当前最小, value}，即辅助栈大小与数据栈保持一致
    push(S->pData, value);
    return true;
}

/**
 * 出栈
 * @param S
 * @param value
 * @return
 */
bool stackMinPop(StackWithMin *S, int *value) {
    if (S == NULL || isStackEmpty(*S->pData)) { return false; }
    // 数据栈和辅助栈都要出栈
    pop(S->pData, value);
    pop(S->pMin, NULL);
    return true;
}

/**
 * 获取当前栈中元素的最小值
 * @param S
 * @return
 */
int min(StackWithMin S) {
    int min = -1;
    if (!getTop(*S.pMin, &min)) {
        printf("空栈!");
    }
    return min;
}

int main() {
    StackWithMin *S = (StackWithMin *) malloc(sizeof(StackWithMin));
    initStackWithMin(S);
    int minNumber = min(*S);
    printf("%d\n", minNumber); // -1

    stackMinPush(S, 1);
    minNumber = min(*S);
    printf("%d\n", minNumber); // 1

    stackMinPush(S, 2);
    minNumber = min(*S);
    printf("%d\n", minNumber); // 1

    stackMinPush(S, -2);
    minNumber = min(*S);
    printf("%d\n", minNumber); // -2

    int top = 0;
    stackMinPop(S, &top);
    minNumber = min(*S);
    printf("%d %d", top, minNumber); // -2 1

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../lib/stack/stack.h"

/**
 * P168 以 pushOrder 序列压栈，判断 popOrder 是否为该栈的出栈顺序
 * @param pushOrder
 * @param popOrder
 * @param length
 * @return
 */
bool isStackPopOrder(int *pushOrder, int *popOrder, int length) {
    if (pushOrder == NULL || popOrder == NULL || length <= 0) { return false; }

    Stack *S = (Stack *) malloc(sizeof(Stack));
    InitStack(S);
    int indexPush = 0;
    int indexPop = 0;

    while (indexPush <= length && indexPop < length) { // 入栈序列索引为 length 时，有可能可以出栈
        int top = 0;
        getTop(*S, &top);
        if (isStackEmpty(*S) || top != popOrder[indexPop]) { // 栈为空或者栈顶元素不等于待出栈元素时，待入栈元素入栈
            if (indexPush == length) { break; }
            push(S, pushOrder[indexPush]);
            indexPush++;
        } else { // 栈顶元素等于待出栈元素时，出栈
            pop(S, NULL);
            indexPop++;
        }
    }
    return indexPop == length; // 匹配时，出栈序列全部被遍历过一次，此时出栈序列索引为 length
}

int main() {
    int pushOrder[] = {1, 2, 3, 4, 5};
    int popOrder1[] = {4, 5, 3, 2, 1};
    int popOrder2[] = {4, 3, 5, 1, 2};
    printf("%d %d", isStackPopOrder(pushOrder, popOrder1, 5), isStackPopOrder(pushOrder, popOrder2, 5));

    return 0;
}

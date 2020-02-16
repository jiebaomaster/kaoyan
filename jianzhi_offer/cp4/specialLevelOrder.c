#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../lib/queue/queue.h"
#include "../lib/stack/stack.h"
#include "../lib/binaryTree/binaryTree.h"

/**
 * P174 层序遍历，每一层的节点打印一行
 * @param T
 */
void levelOrder_OneLevelOneRow(BinaryTree T) {
    if (T == NULL) { return; }

    LinkQueue Q;
    initQueue(&Q);
    enQueue(&Q, T);
    int curLevelNodeNumber = 1; // 当前层剩余待遍历节点
    int nextLevelNodeNumber = 0; // 下一层需要遍历的节点
    BinaryTreeNode *pNode = NULL;
    while (deQueue(&Q, (void **) &pNode)) {
        printf("%d ", pNode->value);
        if (pNode->lChild) { // 子节点存在时，子节点入队，并记录下一层节点数
            enQueue(&Q, pNode->lChild);
            nextLevelNodeNumber++;
        }
        if (pNode->rChild) {
            enQueue(&Q, pNode->rChild);
            nextLevelNodeNumber++;
        }
        curLevelNodeNumber--;
        if (curLevelNodeNumber == 0) { // 当这一层遍历完的时候要换行
            printf("\n");
            curLevelNodeNumber = nextLevelNodeNumber;
            nextLevelNodeNumber = 0;
        }
    }
}

/**
 * P176 按 Z 型路径层序遍历
 * 第一行从左到右，第二行从右到左，以此类推
 * Z 型路线对应先进后出的打印顺序，故使用栈容器；由于需要同时保存上一层打印过的节点和当前层的子节点，则需使用两个栈
 * 如果当前为奇数层，则先保存左子节点后右子节点，偶数层反之
 * @param Y
 */
void levelOrder_zRoute(BinaryTree T) {
    if (T == NULL) { return; }

    Stack *oddLevelStack = (Stack *) malloc(sizeof(Stack)); // 当前层为单数时，存储子节点的栈
    Stack *evenLevelStack = (Stack *) malloc(sizeof(Stack)); // 当前层为双数时，存储子节点的栈
    InitStack(oddLevelStack);
    InitStack(evenLevelStack);

    push(evenLevelStack, T);
    bool isEvenLevel = false; // 当前层树的奇偶性标志，从树的第一层开始
    BinaryTreeNode *pNode = NULL;
    while (!(isStackEmpty(*evenLevelStack) && isStackEmpty(*oddLevelStack))) { // 两个栈都为空时遍历结束退出
        if (isEvenLevel) {
            pop(oddLevelStack, &pNode);
            printf("%d ", pNode->value);
            // 偶数层子节点先右后左
            if (pNode->rChild) { push(evenLevelStack, pNode->rChild); }
            if (pNode->lChild) { push(evenLevelStack, pNode->lChild); }
            if (isStackEmpty(*oddLevelStack)) { // 当前层节点遍历完毕，换行并交换当前层数奇偶性
                isEvenLevel = false;
                printf("\n");
            }
        } else {
            pop(evenLevelStack, &pNode);
            printf("%d ", pNode->value);
            // 奇数层子节点先左后右
            if (pNode->lChild) { push(oddLevelStack, pNode->lChild); }
            if (pNode->rChild) { push(oddLevelStack, pNode->rChild); }
            if (isStackEmpty(*evenLevelStack)) {
                isEvenLevel = true;
                printf("\n");
            }
        }
    }
}

int main() {
    int data[] = {1, 2, 3, 4, NULL_NODE_VALUE, 5, NULL_NODE_VALUE, NULL_NODE_VALUE, 6, NULL_NODE_VALUE, 7, 8, 9,
                  NULL_NODE_VALUE, 10};
    BinaryTree T = constructByLayoutOrder(data, 15);
    levelOrder_OneLevelOneRow(T);
    printf("\n");
    levelOrder_zRoute(T);
    return 0;
}
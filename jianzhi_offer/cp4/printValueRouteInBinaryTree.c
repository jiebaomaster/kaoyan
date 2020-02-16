#include <stdio.h>
#include <stdlib.h>
#include "../lib/binaryTree/binaryTree.h"
#include "../lib/stack/stack.h"

/**
 * 二叉树的前序遍历，遍历到每一个叶子节点判断路径上的节点值之和是否和指定值相等，相等则打印该条路径
 * @param T
 * @param value
 * @param routeStack 存放已访问路径的栈
 * @param curSum 已访问路径上所有节点值之和
 */
void printValueRouteCore(BinaryTree T, int value, Stack *routeStack, int curSum) {
    curSum += T->value;
    push(routeStack, T->value); // 当前节点入栈
    if (!T->lChild && !T->rChild) { // 叶子节点
        if (curSum == value) { // 叶子节点路径和等于指定值时，输出栈中保存的路径
            int *pRoute = routeStack->data;
            while (pRoute != routeStack->top) {
                printf("%d ", *pRoute);
                pRoute++;
            }
            printf("\n");
        }
    }
    if (T->lChild) {
        printValueRouteCore(T->lChild, value, routeStack, curSum);
    }
    if (T->rChild) {
        printValueRouteCore(T->rChild, value, routeStack, curSum);
    }

    pop(routeStack, NULL); // 本节点遍历完成，递归退出时要将本节点出栈，即将该节点从路径中删除
}


/**
 * P182 打印二叉树中节点值的和为输入整数的所有路径
 * @param T
 * @param value
 */
void printValueRouteInBinaryTree(BinaryTree T, int value) {
    if (T == NULL) { return; }
    Stack *routeStack = (Stack *) malloc(sizeof(Stack)); // 存放已访问路径的栈
    InitStack(routeStack);
    printValueRouteCore(T, value, routeStack, 0);
}

int main() {
    int treeData[] = {10, 5, 12, 4, 7, NULL_NODE_VALUE, 0};
    BinaryTree T = constructByLayoutOrder(treeData, 7);
    printValueRouteInBinaryTree(T, 22);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include "../lib/binaryTree/binaryTree.h"

/**
 * 判断 T2 是不是 T1 的子结构
 * @param T1
 * @param T2
 * @return
 */
bool doesTree1HaveTree2(BinaryTree T1, BinaryTree T2) {
    if (T2 == NULL) { return true; } // 递归出口为 T2 的叶子节点
    if (T1 == NULL) { return false; } // T2不为空，T1 为空时可判否

    if (T1->value != T2->value) { return false; }
    else { // 根节点相等时比较左右子树
        return doesTree1HaveTree2(T1->lChild, T2->lChild)
               && doesTree1HaveTree2(T1->rChild, T2->rChild);
    }
}

/**
 * P148 判断二叉树 T2 是否是二叉树 T1 的子结构
 * @param T1
 * @param T2
 * @return
 */
bool hasSubtree(BinaryTree T1, BinaryTree T2) {
    if (T1 == NULL || T2 == NULL) { return false; }

    bool result = false;
    if (T1->value == T2->value) { // 递归先序遍历二叉树 T1，直到找到一个根节点值与 T2 相同的子树
        result = doesTree1HaveTree2(T1, T2);
    }
    if (!result) {
        result = hasSubtree(T1->lChild, T2);
    }
    if (!result) {
        result = hasSubtree(T1->rChild, T2);
    }
    return result;
}

int main() {
    BinaryTree T1 = NULL;
    int preOrderListT1[] = {3, 8, 9, 2, 4, 7, 6};
    int inOrderListT1[] = {9, 8, 4, 2, 7, 3, 6};
    T1 = constructByPreOrderAndInOrder(preOrderListT1, inOrderListT1, 7);

    BinaryTree T2 = NULL;
    int preOrderListT2[] = {8, 9, 2};
    int inOrderListT2[] = {9, 8, 2};
    T2 = constructByPreOrderAndInOrder(preOrderListT2, inOrderListT2, 3);

    printf("%d", hasSubtree(T1, T2));

    return 0;

}
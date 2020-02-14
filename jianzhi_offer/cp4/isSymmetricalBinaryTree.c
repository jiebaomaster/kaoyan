#include <stdio.h>
#include <stdbool.h>
#include "../lib/binaryTree/binaryTree.h"

/**
 * 递归遍历对称的点对，比较其值是否相等，若所有对称点对值相等，则为对称二叉树
 * @param T1
 * @param T2
 * @return
 */
bool isSymmetricalSubTree(BinaryTree T1, BinaryTree T2) {
    if (T1 == NULL && T2 == NULL) { return true; }
    if (T1 == NULL || T2 == NULL) { return false; }
    if (T1->value != T2->value) { return false; }

    // 对称的点呈放射状，递归比较对称的点对值是否相同
    return isSymmetricalSubTree(T1->lChild, T2->rChild)
           && isSymmetricalSubTree(T1->rChild, T2->lChild);
}

/**
 * P159 判断一个二叉树是否是对称的
 * 如果一个二叉树与其镜像二叉树相同，则称其为对称二叉树
 * 对称二叉树的前序序列与其镜像二叉树的前序序列相同
 * @param T
 * @return
 */
bool isSymmetricalBinaryTree(BinaryTree T) {
    if (T == NULL) { return false; }
    return isSymmetricalSubTree(T, T);
}

int main() {
    int data1[] = {8, 6, 6, 5, 7, 7, 5};
    BinaryTree T1 = constructByLayoutOrder(data1, 7);
    printf("%d\n", isSymmetricalBinaryTree(T1));

    int data2[] = {8, 6, 6, 5, 7, 7, 4};
    BinaryTree T2 = constructByLayoutOrder(data2, 7);
    printf("%d\n", isSymmetricalBinaryTree(T2));

    return 0;
}
#pragma once
#define NULL_NODE_VALUE -2147483648 // int 类型能表示的最小数，当一个树中的节点的值为此数时，该节点实际不存在

typedef struct BinaryTreeNode {
    int value; // 节点元素值
    struct BinaryTreeNode *lChild; // 指向左孩子的指针
    struct BinaryTreeNode *rChild; // 指向右孩子的指针
} BinaryTreeNode, *BinaryTree;

/**
 * 先序遍历二叉树
 * @param T
 */
void preOrder(BinaryTree T);

/**
 * 中序遍历二叉树
 * @param T
 */
void inOrder(BinaryTree T);

/**
 * 后序遍历二叉树
 * @param T
 */
void postOrder(BinaryTree T);

/**
 * 层序遍历二叉树
 * @param T
 */
void levelOrder(BinaryTree T);

/**
 * 通过先序遍历序列的中序遍历序列重建二叉树
 * 该二叉树的节点值不能相等
 * @param preOrder
 * @param inOrder
 * @param length
 * @return
 */
BinaryTree constructByPreOrderAndInOrder(int *preOrder, int *inOrder, int length);

/**
 * 用层序遍历序列建立二叉树
 * 序列是一个除了不存在的节点外，所有节点都有两个子节点的二叉树的层序遍历，实际不存在的节点值为 NULL_NODE_VALUE
 * 该二叉树的节点值可以相等
 * @param layoutOrder
 * @param length
 * @return
 */
BinaryTree constructByLayoutOrder(int *layoutOrder, int length);